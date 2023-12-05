#include "header1.h"
#include "c_listas.h"
#include "c_usuario.h"
#include "c_catalogo_a.h"
using namespace std;
CatalogoAdmin::CatalogoAdmin(Listas& lista_has,Listas& lista_viv,Usuario& usuario1)
    :Catalogo(lista_has,lista_viv,usuario1){
}
void CatalogoAdmin::tab_catalogo(){
    cout << "CATALOGO ADMIN\n";
    Catalogo::tab_catalogo();
}