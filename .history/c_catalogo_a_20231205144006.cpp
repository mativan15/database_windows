#include "header1.h"
#include "c_listas.h"
#include "c_usuario.h"
#include "c_catalogo_a.h"

CatalogoAdmin::CatalogoAdmin(Listas& lista_has,Listas& lista_viv,Usuario& usuario1)
    :Catalogo(lista_has,lista_viv,usuario1){
}