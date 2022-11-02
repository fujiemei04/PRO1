#include "Estudiant.hh"
#include <vector>

/* Pre: v no conte repeticions de dni  */
/* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */
 pair<int,int>  max_min_vest(const vector<Estudiant>& v) {
     int n = v.size();
     int posicio_max = -1;
     int posicio_min = -1;
     double nota_max = 0;
     double nota_min = 10;
     int dni_max,dni_min;
     dni_max = dni_min = v[0].consultar_DNI();
     for (int i = 0;i < n;++i) {
        if (v[i].te_nota()) {
            if (v[i].consultar_nota() > nota_max ) {
               nota_max = v[i].consultar_nota();
               dni_max = v[i].consultar_DNI();
               posicio_max = i;
            }
            else if (v[i].consultar_nota() == nota_max) {
                if (dni_max > v[i].consultar_DNI()) {
                    posicio_max = i;
                    dni_max = v[i].consultar_DNI();
                }
            }
            else if (v[i].consultar_nota() < nota_min){
               nota_min = v[i].consultar_nota();
               posicio_min = i;
               dni_min = v[i].consultar_DNI();
            }
            else if (v[i].consultar_nota() == nota_min) {
                if (v[i].consultar_DNI() < dni_min) {
                    posicio_min = i;
                    dni_min = v[i].consultar_DNI();
                }
            }
        }
    }
    return make_pair(posicio_max,posicio_min);
}
