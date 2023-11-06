#include <iostream>
#include <iomanip>
#include <string>
#include "wa.h"
#include "clase_pedidos.h"
#include "clase_producto.h"
using namespace std;

void error_valor(){
    cout << "\nValor incorrecto!!! Ingrese una opcion valida:\n\n"; 
	cin.clear();           
    cin.ignore(100, '\n');
}
void instanciar_muestras(Producto array_libros_has[], Producto array_libros_viv[]){
	//has
	array_libros_has[0] = Producto(1234567890123, "Matematica - Crecemos J.", "Lib. Act.", "Primaria", 1, "Matematica", 69.9, 2349);
	array_libros_has[1] = Producto(2345678901234, "Ciencias Naturales - Aprendemos", "Lib. Tex.", "Primaria", 2, "Ciencias Naturales", 150.0, 1357);
	array_libros_has[2] = Producto(3456789012345, "Lenguaje - Saber C.", "Lib. Tex.", "Secundaria", 3, "Lenguaje", 129.5, 1132);
	array_libros_has[3] = Producto(4567890123456, "Geografia - Aprendemos", "Pack", "Primaria", 4, "Geografia", 60.0, 1598);
	array_libros_has[4] = Producto(5678901234567, "Ciencias Naturales - Crecemos J.", "Pack", "Secundaria", 5, "Ciencias Naturales", 99.9, 1783);
	array_libros_has[5] = Producto(6789012345678, "Lenguaje - Estudio D.", "Pack", "Secundaria", 4, "Lenguaje", 118.5, 2281);
	array_libros_has[6] = Producto(7890123456789, "Ciencias Naturales - Saber C.", "Lib. Act.", "Secundaria", 3, "Ciencias Naturales", 39.9, 315);
	array_libros_has[7] = Producto(8901234567890, "Lenguaje - Aprendemos", "Lib. Act.", "Secundaria", 2, "Lenguaje", 92.5, 423);
	array_libros_has[8] = Producto(9012345678901, "Geografia - Saber C.", "Pack", "Primaria", 1, "Geografia", 145.0, 1529);
	array_libros_has[9] = Producto(6323456789012, "Matematica - Estudio D.", "Lib. Tex.", "Primaria", 4, "Matematica", 122.9, 1759);
	array_libros_has[10] = Producto(1230123012301, "Geografia - Crecemos J.", "Pack", "Secundaria", 5, "Geografia", 115.0, 2385);
	array_libros_has[11] = Producto(5678012304567, "Lenguaje - Aprendemos", "Lib. Tex.", "Primaria", 3, "Lenguaje", 99.9, 1081);
	array_libros_has[12] = Producto(2345670123012, "Matematica - Aprendemos", "Pack", "Secundaria", 1, "Matematica", 123.0, 2075);
	array_libros_has[13] = Producto(1234568901345, "Ciencias Naturales - Crecemos J.", "Lib. Tex.", "Secundaria", 2, "Ciencias Naturales", 75.5, 1046);
	array_libros_has[14] = Producto(6789012345032, "Lenguaje - Saber C.", "Pack", "Primaria", 4, "Lenguaje", 95.0, 1590);
	array_libros_has[15] = Producto(5432109654321, "Matematica - Estudio D.", "Pack", "Primaria", 5, "Matematica", 102.0, 1732);
	array_libros_has[16] = Producto(2345123401234, "Ciencias Naturales - Saber C.", "Lib. Act.", "Primaria", 4, "Ciencias Naturales", 69.0, 1980);
	array_libros_has[17] = Producto(9012345690123, "Geografia - Aprendemos", "Lib. Tex.", "Secundaria", 3, "Geografia", 76.0, 1947);
	array_libros_has[18] = Producto(4567812304567, "Lenguaje - Crecemos J.", "Lib. Act.", "Secundaria", 2, "Lenguaje", 124.9, 1122);
	array_libros_has[19] = Producto(1230456789012, "Matematica - Crecemos J.", "Lib. Act.", "Primaria", 1, "Matematica", 64.5, 2267);
	array_libros_has[20] = Producto(5432109876543, "Ciencias Naturales - Aprendemos", "Pack", "Secundaria", 5, "Ciencias Naturales", 129.0, 1776);
	array_libros_has[21] = Producto(2345123401234, "Lenguaje - Estudio D.", "Lib. Tex.", "Primaria", 4, "Lenguaje", 87.0, 1175);
	array_libros_has[22] = Producto(7890123456098, "Geografia - Saber C.", "Pack", "Secundaria", 3, "Geografia", 60.0, 1839);
	array_libros_has[23] = Producto(4567812304512, "Matematica - Estudio D.", "Lib. Act.", "Primaria", 5, "Matematica", 130.0, 2352);
	array_libros_has[24] = Producto(9012345690876, "Ciencias Naturales - Saber C.", "Pack", "Secundaria", 1, "Ciencias Naturales", 72.0, 1096);
	array_libros_has[25] = Producto(5432165987654, "Lenguaje - Aprendemos", "Lib. Act.", "Secundaria", 4, "Lenguaje", 139.0, 1591);
	array_libros_has[26] = Producto(9123456789965, "Geografia - Crecemos J.", "Lib. Tex.", "Primaria", 2, "Geografia", 87.5, 2437);
	array_libros_has[27] = Producto(2345123456789, "Matematica - Aprendemos", "Pack", "Primaria", 3, "Matematica", 96.9, 1067);
	array_libros_has[28] = Producto(7890123456012, "Ciencias Naturales - Aprendemos", "Lib. Act.", "Secundaria", 2, "Ciencias Naturales", 92.0, 2367);
	array_libros_has[29] = Producto(1230456789678, "Lenguaje - Estudio D.", "Pack", "Secundaria", 1, "Lenguaje", 107.5, 1534);
	array_libros_has[30] = Producto(5678109876543, "Matematica - Crecemos J.", "Lib. Act.", "Secundaria", 4, "Matematica", 109.0, 1629);
	array_libros_has[31] = Producto(2345123490123, "Ciencias Naturales - Saber C.", "Lib. Act.", "Secundaria", 5, "Ciencias Naturales", 52.9, 2282);
	array_libros_has[32] = Producto(9012345690123, "Lenguaje - Saber C.", "Lib. Tex.", "Primaria", 4, "Lenguaje", 111.0, 2472);
	array_libros_has[33] = Producto(4567812301234, "Geografia - Aprendemos", "Pack", "Secundaria", 3, "Geografia", 104.0, 1196);
	array_libros_has[34] = Producto(5432109876987, "Matematica - Estudio D.", "Lib. Act.", "Secundaria", 2, "Matematica", 69.0, 1454);
	array_libros_has[35] = Producto(2345123456781, "Ciencias Naturales - Crecemos J.", "Lib. Act.", "Primaria", 1, "Ciencias Naturales", 115.5, 2045);
	array_libros_has[36] = Producto(7890123456786, "Lenguaje - Aprendemos", "Pack", "Primaria", 2, "Lenguaje", 108.0, 1795);
	array_libros_has[37] = Producto(9012345690122, "Geografia - Saber C.", "Lib. Act.", "Primaria", 3, "Geografia", 65.5, 1177);
	array_libros_has[38] = Producto(5432109876549, "Matematica - Crecemos J.", "Lib. Act.", "Secundaria", 4, "Matematica", 59.0, 1904);
	array_libros_has[39] = Producto(2345123490126, "Ciencias Naturales - Aprendemos", "Lib. Tex.", "Primaria", 5, "Ciencias Naturales", 97.0, 1067);
	array_libros_has[40] = Producto(7890123456012, "Lenguaje - Estudio D.", "Pack", "Secundaria", 1, "Lenguaje", 120.0, 2291);
	array_libros_has[41] = Producto(9012345690123, "Matematica - Saber C.", "Pack", "Secundaria", 2, "Matematica", 103.0, 2398);
	array_libros_has[42] = Producto(2345123490123, "Ciencias Naturales - Crecemos J.", "Lib. Tex.", "Secundaria", 3, "Ciencias Naturales", 105.9, 1077);
	array_libros_has[43] = Producto(7890123456789, "Lenguaje - Aprendemos", "Pack", "Primaria", 4, "Lenguaje", 129.0, 2457);
	array_libros_has[44] = Producto(5678109876543, "Geografia - Aprendemos", "Lib. Act.", "Primaria", 5, "Geografia", 71.9, 1445);
	array_libros_has[45] = Producto(6123456789965, "Matematica - Estudio D.", "Lib. Act.", "Secundaria", 4, "Matematica", 112.0, 1846);
	array_libros_has[46] = Producto(2345123456789, "Ciencias Naturales - Saber C.", "Lib. Act.", "Primaria", 2, "Ciencias Naturales", 102.5, 1142);
	array_libros_has[47] = Producto(9012345690123, "Lenguaje - Saber C.", "Lib. Tex.", "Secundaria", 1, "Lenguaje", 90.0, 2308);
	array_libros_has[48] = Producto(4567812301234, "Geografia - Crecemos J.", "Pack", "Primaria", 3, "Geografia", 64.9, 1282);
	array_libros_has[49] = Producto(1230456789012, "Matematica - Aprendemos", "Pack", "Primaria", 5, "Matematica", 94.0, 2166);
	array_libros_has[50] = Producto(5432109876543, "Ciencias Naturales - Crecemos J.", "Lib. Tex.", "Secundaria", 4, "Ciencias Naturales", 65.0, 1532);
	array_libros_has[51] = Producto(2345123490126, "Lenguaje - Aprendemos", "Pack", "Primaria", 1, "Lenguaje", 116.5, 2057);
	array_libros_has[52] = Producto(7890123456012, "Matematica - Estudio D.", "Lib. Tex.", "Secundaria", 5, "Matematica", 125.0, 2134);
	array_libros_has[53] = Producto(9012345690123, "Ciencias Naturales - Saber C.", "Pack", "Secundaria", 2, "Ciencias Naturales", 71.0, 1977);
	array_libros_has[54] = Producto(2345123490123, "Geografia - Aprendemos", "Lib. Act.", "Primaria", 4, "Geografia", 82.9, 1062);
	array_libros_has[55] = Producto(5678109876543, "Lenguaje - Crecemos J.", "Lib. Act.", "Secundaria", 3, "Lenguaje", 73.0, 1998);
	array_libros_has[56] = Producto(7123456789965, "Matematica - Crecemos J.", "Lib. Act.", "Primaria", 2, "Matematica", 80.5, 1597);
	array_libros_has[57] = Producto(2345123456789, "Ciencias Naturales - Aprendemos", "Pack", "Secundaria", 1, "Ciencias Naturales", 115.9, 1172);
	array_libros_has[58] = Producto(7890123456786, "Geografia - Saber C.", "Pack", "Primaria", 5, "Geografia", 65.0, 2064);
	array_libros_has[59] = Producto(9012345690122, "Lenguaje - Estudio D.", "Lib. Act.", "Secundaria", 2, "Lenguaje", 99.0, 1977);
	array_libros_has[60] = Producto(5432109876549, "Matematica - Saber C.", "Lib. Act.", "Secundaria", 3, "Matematica", 75.0, 1822);
	array_libros_has[61] = Producto(2345123490123, "Ciencias Naturales - Crecemos J.", "Lib. Tex.", "Primaria", 4, "Ciencias Naturales", 93.9, 1504);
	array_libros_has[62] = Producto(7890123456012, "Lenguaje - Aprendemos", "Pack", "Primaria", 3, "Lenguaje", 128.0, 2127);
	array_libros_has[63] = Producto(9012345690123, "Geografia - Estudio D.", "Pack", "Secundaria", 5, "Geografia", 81.0, 2154);
	array_libros_has[64] = Producto(2345123490123, "Matematica - Aprendemos", "Lib. Tex.", "Secundaria", 1, "Matematica", 90.9, 1172);
	array_libros_has[65] = Producto(7890123456789, "Ciencias Naturales - Saber C.", "Lib. Act.", "Secundaria", 4, "Ciencias Naturales", 61.0, 1856);
	array_libros_has[66] = Producto(5432109876543, "Lenguaje - Crecemos J.", "Lib. Act.", "Primaria", 5, "Lenguaje", 116.9, 1647);
	array_libros_has[67] = Producto(3123456789965, "Matematica - Crecemos J.", "Lib. Act.", "Primaria", 3, "Matematica", 67.0, 1247);
	array_libros_has[68] = Producto(2345123456789, "Ciencias Naturales - Aprendemos", "Pack", "Secundaria", 2, "Ciencias Naturales", 87.5, 2085);
	array_libros_has[69] = Producto(7890123456786, "Geografia - Saber C.", "Pack", "Secundaria", 1, "Geografia", 54.0, 1442);
	array_libros_has[70] = Producto(9012345690122, "Lenguaje - Estudio D.", "Lib. Tex.", "Primaria", 4, "Lenguaje", 110.9, 1985);
	array_libros_has[71] = Producto(5432109876549, "Matematica - Saber C.", "Lib. Act.", "Secundaria", 5, "Matematica", 67.0, 1367);
	array_libros_has[72] = Producto(2345123490123, "Ciencias Naturales - Crecemos J.", "Lib. Act.", "Primaria", 2, "Ciencias Naturales", 118.5, 1954);
	array_libros_has[73] = Producto(7890123456012, "Lenguaje - Aprendemos", "Pack", "Secundaria", 3, "Lenguaje", 84.0, 1414);
	array_libros_has[74] = Producto(9012345690123, "Geografia - Estudio D.", "Pack", "Secundaria", 4, "Geografia", 90.9, 1282);
	array_libros_has[75] = Producto(2345123490123, "Matematica - Aprendemos", "Lib. Tex.", "Primaria", 1, "Matematica", 99.0, 2022);
	array_libros_has[76] = Producto(7890123456789, "Ciencias Naturales - Saber C.", "Lib. Act.", "Secundaria", 2, "Ciencias Naturales", 105.0, 1857);
	array_libros_has[77] = Producto(5432109876543, "Lenguaje - Crecemos J.", "Lib. Act.", "Primaria", 5, "Lenguaje", 109.0, 1637);
	array_libros_has[78] = Producto(4123456789965, "Matematica - Crecemos J.", "Lib. Act.", "Primaria", 3, "Matematica", 60.5, 1202);
	array_libros_has[79] = Producto(2345123456789, "Ciencias Naturales - Aprendemos", "Pack", "Secundaria", 4, "Ciencias Naturales", 79.9, 2064);
	array_libros_has[80] = Producto(7890123456786, "Geografia - Saber C.", "Pack", "Secundaria", 1, "Geografia", 62.0, 1327);
	array_libros_has[81] = Producto(9012345690122, "Lenguaje - Estudio D.", "Lib. Tex.", "Primaria", 4, "Lenguaje", 121.9, 1187);
	array_libros_has[82] = Producto(5432109876549, "Matematica - Saber C.", "Lib. Act.", "Secundaria", 5, "Matematica", 84.0, 1892);
	array_libros_has[83] = Producto(2345123490123, "Ciencias Naturales - Crecemos J.", "Lib. Act.", "Primaria", 2, "Ciencias Naturales", 98.5, 1844);
	array_libros_has[84] = Producto(7890123456012, "Lenguaje - Aprendemos", "Pack", "Secundaria", 3, "Lenguaje", 80.0, 1763);
	array_libros_has[85] = Producto(9012345690123, "Geografia - Estudio D.", "Pack", "Secundaria", 4, "Geografia", 95.9, 1457);
	array_libros_has[86] = Producto(2345123490123, "Matematica - Aprendemos", "Lib. Tex.", "Primaria", 1, "Matematica", 94.0, 1423);
	array_libros_has[87] = Producto(5432109876543, "Ciencias Naturales - Saber C.", "Lib. Act.", "Secundaria", 2, "Ciencias Naturales", 98.0, 1342);
	array_libros_has[88] = Producto(7890123456786, "Lenguaje - Crecemos J.", "Lib. Act.", "Primaria", 5, "Lenguaje", 81.9, 2147);
	array_libros_has[89] = Producto(5123456789965, "Matematica - Crecemos J.", "Lib. Tex.", "Primaria", 3, "Matematica", 79.0, 1536);
	array_libros_has[90] = Producto(2345123456789, "Ciencias Naturales - Aprendemos", "Pack", "Secundaria", 4, "Ciencias Naturales", 82.5, 1785);
	array_libros_has[91] = Producto(7890123456789, "Geografia - Saber C.", "Pack", "Secundaria", 1, "Geografia", 101.0, 1672);
	array_libros_has[92] = Producto(9012345690122, "Lenguaje - Estudio D.", "Lib. Act.", "Primaria", 4, "Lenguaje", 88.9, 1647);
	array_libros_has[93] = Producto(5432109876549, "Matematica - Saber C.", "Lib. Act.", "Secundaria", 5, "Matematica", 87.0, 1992);
	array_libros_has[94] = Producto(2345123490123, "Ciencias Naturales - Crecemos J.", "Lib. Act.", "Primaria", 2, "Ciencias Naturales", 95.9, 1864);
	array_libros_has[95] = Producto(7890123456012, "Lenguaje - Aprendemos", "Pack", "Secundaria", 3, "Lenguaje", 102.0, 1842);
	array_libros_has[96] = Producto(9012345690123, "Geografia - Estudio D.", "Pack", "Secundaria", 4, "Geografia", 75.0, 1647);
	array_libros_has[97] = Producto(2345123490123, "Matematica - Aprendemos", "Lib. Tex.", "Primaria", 1, "Matematica", 87.0, 1998);
	array_libros_has[98] = Producto(5432109876543, "Ciencias Naturales - Saber C.", "Lib. Act.", "Secundaria", 2, "Ciencias Naturales", 94.0, 1864);
	array_libros_has[99] = Producto(7890123456786, "Lenguaje - Crecemos J.", "Lib. Act.", "Primaria", 5, "Lenguaje", 73.9, 2047);	
	
	//vivos
	array_libros_viv[0] = Producto(5432101234567, "Matematica - Aprendemos", "Pack", "Secundaria", 3, "Matematica", 99.0, 1747);
	array_libros_viv[1] = Producto(9012345690876, "Ciencias Naturales - Saber C.", "Lib. Act.", "Primaria", 2, "Ciencias Naturales", 88.9, 1944);
	array_libros_viv[2] = Producto(1234567890123, "Lenguaje - Estudio D.", "Pack", "Primaria", 1, "Lenguaje", 70.0, 1607);
	array_libros_viv[3] = Producto(2345012345678, "Geografia - Aprendemos", "Pack", "Secundaria", 5, "Geografia", 112.0, 1627);
	array_libros_viv[4] = Producto(4567890123098, "Matematica - Crecemos J.", "Lib. Tex.", "Primaria", 4, "Matematica", 83.0, 1692);
	array_libros_viv[5] = Producto(5678901987654, "Lenguaje - Saber C.", "Lib. Tex.", "Secundaria", 3, "Lenguaje", 105.0, 1447);
	array_libros_viv[6] = Producto(6789012378901, "Ciencias Naturales - Crecemos J.", "Lib. Act.", "Primaria", 2, "Ciencias Naturales", 75.0, 1972);
	array_libros_viv[7] = Producto(7890123456789, "Geografia - Saber C.", "Lib. Act.", "Primaria", 1, "Geografia", 65.0, 1837);
	array_libros_viv[8] = Producto(8901234901234, "Matematica - Estudio D.", "Pack", "Secundaria", 5, "Matematica", 119.9, 1422);
	array_libros_viv[9] = Producto(4123456789901, "Lenguaje - Aprendemos", "Lib. Act.", "Secundaria", 4, "Lenguaje", 94.0, 1907);
	array_libros_viv[10] = Producto(1234098765432, "Ciencias Naturales - Saber C.", "Pack", "Primaria", 3, "Ciencias Naturales", 81.0, 1282);
	array_libros_viv[11] = Producto(9012345690212, "Geografia - Crecemos J.", "Pack", "Primaria", 2, "Geografia", 70.9, 1657);
	array_libros_viv[12] = Producto(5678090123456, "Matematica - Aprendemos", "Lib. Tex.", "Secundaria", 1, "Matematica", 90.0, 1722);
	array_libros_viv[13] = Producto(2345690123409, "Lenguaje - Estudio D.", "Pack", "Secundaria", 5, "Lenguaje", 110.0, 1347);
	array_libros_viv[14] = Producto(5432109876098, "Ciencias Naturales - Saber C.", "Lib. Act.", "Primaria", 4, "Ciencias Naturales", 64.9, 1752);
	array_libros_viv[15] = Producto(6789012345301, "Geografia - Crecemos J.", "Lib. Act.", "Primaria", 3, "Geografia", 88.0, 1837);
	array_libros_viv[16] = Producto(9012345690765, "Matematica - Crecemos J.", "Lib. Tex.", "Secundaria", 2, "Matematica", 95.0, 1222);
	array_libros_viv[17] = Producto(2345678123901, "Lenguaje - Aprendemos", "Lib. Tex.", "Secundaria", 1, "Lenguaje", 101.0, 1487);
	array_libros_viv[18] = Producto(5432109823456, "Ciencias Naturales - Estudio D.", "Lib. Act.", "Primaria", 5, "Ciencias Naturales", 73.9, 1922);
	array_libros_viv[19] = Producto(4567890123987, "Geografia - Crecemos J.", "Pack", "Secundaria", 4, "Geografia", 105.0, 1727);
	array_libros_viv[20] = Producto(9012345612345, "Matematica - Saber C.", "Lib. Act.", "Primaria", 3, "Matematica", 85.0, 1247);
	array_libros_viv[21] = Producto(1234501234309, "Lenguaje - Aprendemos", "Lib. Act.", "Primaria", 2, "Lenguaje", 87.0, 1432);
	array_libros_viv[22] = Producto(9012345690012, "Ciencias Naturales - Estudio D.", "Pack", "Secundaria", 5, "Ciencias Naturales", 105.0, 1307);
	array_libros_viv[23] = Producto(5678901234501, "Geografia - Crecemos J.", "Pack", "Primaria", 4, "Geografia", 64.9, 1582);
	array_libros_viv[24] = Producto(6789012345098, "Matematica - Saber C.", "Lib. Tex.", "Secundaria", 3, "Matematica", 75.0, 1747);
	array_libros_viv[25] = Producto(7890123456001, "Lenguaje - Aprendemos", "Lib. Tex.", "Primaria", 2, "Lenguaje", 100.0, 1832);
	array_libros_viv[26] = Producto(9012345612345, "Ciencias Naturales - Estudio D.", "Lib. Act.", "Primaria", 1, "Ciencias Naturales", 79.0, 1247);
	array_libros_viv[27] = Producto(1234501234309, "Geografia - Crecemos J.", "Lib. Act.", "Secundaria", 5, "Geografia", 109.0, 1442);
	array_libros_viv[28] = Producto(9012345690012, "Matematica - Saber C.", "Pack", "Primaria", 4, "Matematica", 70.9, 1557);
	array_libros_viv[29] = Producto(5678901234501, "Lenguaje - Aprendemos", "Lib. Tex.", "Secundaria", 3, "Lenguaje", 85.0, 1282);
	array_libros_viv[30] = Producto(6789012345098, "Ciencias Naturales - Estudio D.", "Pack", "Primaria", 2, "Ciencias Naturales", 95.0, 1927);
	array_libros_viv[31] = Producto(7890123456001, "Geografia - Crecemos J.", "Pack", "Secundaria", 1, "Geografia", 74.9, 1642);
	array_libros_viv[32] = Producto(9012345612345, "Matematica - Saber C.", "Lib. Act.", "Primaria", 5, "Matematica", 80.0, 1457);
	array_libros_viv[33] = Producto(1234501234309, "Lenguaje - Aprendemos", "Lib. Act.", "Secundaria", 4, "Lenguaje", 104.0, 1222);
	array_libros_viv[34] = Producto(9012345690012, "Ciencias Naturales - Estudio D.", "Lib. Tex.", "Secundaria", 3, "Ciencias Naturales", 75.0, 1597);
	array_libros_viv[35] = Producto(5678901234501, "Geografia - Crecemos J.", "Lib. Act.", "Primaria", 2, "Geografia", 92.0, 1942);
	array_libros_viv[36] = Producto(6789012345098, "Matematica - Saber C.", "Pack", "Primaria", 1, "Matematica", 67.9, 1707);
	array_libros_viv[37] = Producto(7890123456001, "Lenguaje - Aprendemos", "Lib. Tex.", "Secundaria", 5, "Lenguaje", 88.0, 1542);
	array_libros_viv[38] = Producto(9012345612345, "Ciencias Naturales - Estudio D.", "Pack", "Primaria", 4, "Ciencias Naturales", 72.0, 1877);
	array_libros_viv[39] = Producto(1234501234309, "Geografia - Crecemos J.", "Pack", "Secundaria", 3, "Geografia", 99.0, 1722);
	array_libros_viv[40] = Producto(9012345690012, "Matematica - Saber C.", "Lib. Tex.", "Primaria", 2, "Matematica", 95.0, 1887);
	array_libros_viv[41] = Producto(5678901234501, "Lenguaje - Aprendemos", "Lib. Act.", "Secundaria", 1, "Lenguaje", 104.0, 1752);
	array_libros_viv[42] = Producto(6789012345098, "Ciencias Naturales - Estudio D.", "Lib. Act.", "Primaria", 5, "Ciencias Naturales", 69.9, 1747);
	array_libros_viv[43] = Producto(7890123456001, "Geografia - Crecemos J.", "Lib. Tex.", "Secundaria", 4, "Geografia", 80.0, 1282);
	array_libros_viv[44] = Producto(9012345612345, "Matematica - Saber C.", "Pack", "Primaria", 3, "Matematica", 100.0, 1927);
	array_libros_viv[45] = Producto(1234501234309, "Lenguaje - Aprendemos", "Pack", "Secundaria", 2, "Lenguaje", 72.9, 1642);
	array_libros_viv[46] = Producto(9012345690012, "Ciencias Naturales - Estudio D.", "Lib. Act.", "Primaria", 1, "Ciencias Naturales", 73.0, 1457);
	array_libros_viv[47] = Producto(5678901234501, "Geografia - Crecemos J.", "Lib. Act.", "Secundaria", 5, "Geografia", 98.0, 1222);
	array_libros_viv[48] = Producto(6789012345098, "Matematica - Saber C.", "Lib. Tex.", "Primaria", 4, "Matematica", 65.9, 1997);
	array_libros_viv[49] = Producto(7890123456001, "Lenguaje - Aprendemos", "Lib. Tex.", "Primaria", 3, "Lenguaje", 82.0, 1522);
	array_libros_viv[50] = Producto(9012345612345, "Ciencias Naturales - Estudio D.", "Pack", "Secundaria", 2, "Ciencias Naturales", 102.0, 1847);
	array_libros_viv[51] = Producto(1234501234309, "Geografia - Crecemos J.", "Pack", "Primaria", 1, "Geografia", 74.0, 1582);
	array_libros_viv[52] = Producto(9012345690012, "Matematica - Saber C.", "Lib. Act.", "Primaria", 5, "Matematica", 91.0, 1927);
	array_libros_viv[53] = Producto(5678901234501, "Lenguaje - Aprendemos", "Lib. Act.", "Secundaria", 4, "Lenguaje", 74.9, 1942);
	array_libros_viv[54] = Producto(6789012345098, "Ciencias Naturales - Estudio D.", "Lib. Tex.", "Primaria", 3, "Ciencias Naturales", 78.0, 1907);
	array_libros_viv[55] = Producto(7890123456001, "Geografia - Crecemos J.", "Lib. Tex.", "Secundaria", 2, "Geografia", 101.0, 1742);
	array_libros_viv[56] = Producto(9012345612345, "Matematica - Saber C.", "Pack", "Primaria", 1, "Matematica", 85.0, 1887);
	array_libros_viv[57] = Producto(1234501234309, "Lenguaje - Aprendemos", "Pack", "Secundaria", 5, "Lenguaje", 98.0, 1282);
	array_libros_viv[58] = Producto(9012345690012, "Ciencias Naturales - Estudio D.", "Lib. Act.", "Primaria", 4, "Ciencias Naturales", 73.0, 1757);
	array_libros_viv[59] = Producto(5678901234501, "Geografia - Crecemos J.", "Lib. Act.", "Secundaria", 3, "Geografia", 95.0, 1942);
	array_libros_viv[60] = Producto(6789012345098, "Matematica - Saber C.", "Lib. Tex.", "Primaria", 2, "Matematica", 72.9, 1847);
	array_libros_viv[61] = Producto(7890123456001, "Lenguaje - Aprendemos", "Lib. Tex.", "Primaria", 1, "Lenguaje", 74.0, 1602);
	array_libros_viv[62] = Producto(9012345612345, "Ciencias Naturales - Estudio D.", "Pack", "Secundaria", 5, "Ciencias Naturales", 95.0, 1477);
	array_libros_viv[63] = Producto(1234501234309, "Geografia - Crecemos J.", "Pack", "Primaria", 4, "Geografia", 71.9, 1822);
	array_libros_viv[64] = Producto(9012345690012, "Matematica - Saber C.", "Lib. Act.", "Primaria", 3, "Matematica", 68.0, 1847);
	array_libros_viv[65] = Producto(5678901234501, "Lenguaje - Aprendemos", "Lib. Act.", "Secundaria", 2, "Lenguaje", 75.0, 1922);
	array_libros_viv[66] = Producto(6789012345098, "Ciencias Naturales - Estudio D.", "Lib. Tex.", "Primaria", 1, "Ciencias Naturales", 99.0, 1577);
	array_libros_viv[67] = Producto(7890123456001, "Geografia - Crecemos J.", "Lib. Tex.", "Secundaria", 5, "Geografia", 88.0, 1902);
	array_libros_viv[68] = Producto(9012345612345, "Matematica - Saber C.", "Pack", "Primaria", 4, "Matematica", 102.0, 1587);
	array_libros_viv[69] = Producto(1234501234309, "Lenguaje - Aprendemos", "Pack", "Secundaria", 3, "Lenguaje", 76.9, 1842);
	array_libros_viv[70] = Producto(9012345690012, "Ciencias Naturales - Estudio D.", "Lib. Act.", "Primaria", 2, "Ciencias Naturales", 95.0, 1927);
	array_libros_viv[71] = Producto(5678901234501, "Geografia - Crecemos J.", "Lib. Act.", "Secundaria", 1, "Geografia", 80.0, 1557);
	array_libros_viv[72] = Producto(6789012345098, "Matematica - Saber C.", "Lib. Tex.", "Primaria", 5, "Matematica", 71.9, 1822);
	array_libros_viv[73] = Producto(7890123456001, "Lenguaje - Aprendemos", "Lib. Tex.", "Primaria", 4, "Lenguaje", 79.0, 1477);
	array_libros_viv[74] = Producto(9012345612345, "Ciencias Naturales - Estudio D.", "Pack", "Secundaria", 3, "Ciencias Naturales", 100.0, 1842);
	array_libros_viv[75] = Producto(1234501234309, "Geografia - Crecemos J.", "Pack", "Primaria", 2, "Geografia", 68.9, 1757);
	array_libros_viv[76] = Producto(9012345690012, "Matematica - Saber C.", "Lib. Act.", "Secundaria", 5, "Matematica", 92.0, 1922);
	array_libros_viv[77] = Producto(5678901234501, "Lenguaje - Aprendemos", "Lib. Act.", "Primaria", 4, "Lenguaje", 74.9, 1947);
	array_libros_viv[78] = Producto(6789012345098, "Ciencias Naturales - Estudio D.", "Lib. Tex.", "Primaria", 3, "Ciencias Naturales", 78.0, 1822);
	array_libros_viv[79] = Producto(7890123456001, "Geografia - Crecemos J.", "Lib. Tex.", "Secundaria", 2, "Geografia", 75.0, 1907);
	array_libros_viv[80] = Producto(9012345612345, "Matematica - Saber C.", "Pack", "Primaria", 1, "Matematica", 99.0, 1742);
	array_libros_viv[81] = Producto(1234501234309, "Lenguaje - Aprendemos", "Pack", "Secundaria", 5, "Lenguaje", 88.0, 1577);
	array_libros_viv[82] = Producto(9012345690012, "Ciencias Naturales - Estudio D.", "Lib. Act.", "Primaria", 4, "Ciencias Naturales", 69.9, 1902);
	array_libros_viv[83] = Producto(5678901234501, "Geografia - Crecemos J.", "Pack", "Secundaria", 3, "Geografia", 101.0, 1827);
	array_libros_viv[84] = Producto(6789012345098, "Matematica - Saber C.", "Lib. Tex.", "Primaria", 2, "Matematica", 75.0, 1742);
	array_libros_viv[85] = Producto(7890123456001, "Lenguaje - Aprendemos", "Lib. Tex.", "Primaria", 1, "Lenguaje", 98.0, 1597);
	array_libros_viv[86] = Producto(9012345612345, "Ciencias Naturales - Estudio D.", "Pack", "Secundaria", 5, "Ciencias Naturales", 80.0, 1742);
	array_libros_viv[87] = Producto(1234501234309, "Geografia - Crecemos J.", "Lib. Act.", "Primaria", 4, "Geografia", 71.9, 1927);
	array_libros_viv[88] = Producto(9012345690012, "Matematica - Saber C.", "Lib. Tex.", "Secundaria", 3, "Matematica", 85.0, 1752);
	array_libros_viv[89] = Producto(5678901234501, "Lenguaje - Aprendemos", "Lib. Act.", "Secundaria", 2, "Lenguaje", 75.0, 1847);
	array_libros_viv[90] = Producto(6789012345098, "Ciencias Naturales - Estudio D.", "Lib. Tex.", "Primaria", 1, "Ciencias Naturales", 100.0, 1702);
	array_libros_viv[91] = Producto(7890123456001, "Geografia - Crecemos J.", "Lib. Tex.", "Secundaria", 5, "Geografia", 88.0, 1477);
	array_libros_viv[92] = Producto(9012345612345, "Matematica - Saber C.", "Pack", "Primaria", 4, "Matematica", 69.9, 1842);
	array_libros_viv[93] = Producto(1234501234309, "Lenguaje - Aprendemos", "Pack", "Secundaria", 3, "Lenguaje", 100.0, 1907);
	array_libros_viv[94] = Producto(9012345690012, "Ciencias Naturales - Estudio D.", "Lib. Act.", "Primaria", 2, "Ciencias Naturales", 68.0, 1742);
	array_libros_viv[95] = Producto(5678901234501, "Geografia - Crecemos J.", "Pack", "Secundaria", 1, "Geografia", 76.0, 1902);
	array_libros_viv[96] = Producto(6789012345098, "Matematica - Saber C.", "Lib. Tex.", "Primaria", 5, "Matematica", 98.0, 1827);
	array_libros_viv[97] = Producto(7890123456001, "Lenguaje - Aprendemos", "Lib. Tex.", "Primaria", 4, "Lenguaje", 71.9, 1702);
	array_libros_viv[98] = Producto(9012345612345, "Ciencias Naturales - Estudio D.", "Pack", "Secundaria", 3, "Ciencias Naturales", 85.0, 1757);
	array_libros_viv[99] = Producto(1234501234309, "Geografia - Crecemos J.", "Lib. Act.", "Primaria", 2, "Geografia", 78.0, 1922);

}
void print_tabla_libros(Producto array_libros[]){
	//system("cls");
	cout << left << setw(18) << "ISBN" << left << setw(38) << "Titulo" << left << setw(20) << "Descripcion" << left << setw(15) << "Nivel" << left << setw(12) << "Grado" << left << setw(22) << "Area"   << left << setw(12) << "Price" << left << setw(8) << "Stock" << endl;

    for (int i = 0; i < 25; i++){
        cout << left << setw(18) << array_libros[i].codigoISBN 
			<< left << setw(38) << array_libros[i].nombreLibro
            << left << setw(20) << array_libros[i].descripcionLib 
			<< left << setw(15) << array_libros[i].nivel
			<< left << setw(12) << array_libros[i].grado
			<< left << setw(22) << array_libros[i].area
			<< left << setw(12) << array_libros[i].precio
            << left << setw(8) << array_libros[i].stock << endl;
    }
}

void pantalla_start(Producto array_libros_has[], Producto array_libros_viv[], Pedido Pedido1){
	bool r= true;
	system("cls");
		cout << "\x1B[1;97m" << "\n\t\t\t\t\tSales Management Dashboard - Santillana" << "\x1B[m \n";
		cout<< "\x1B[1;97m" << "\n\tBienvenido" << "\x1B[m \n\n";
		cout<< "\x1B[1;97m" << "\n\tPara comenzar, cree un usuario" << "\x1B[m \n";
		char usuario[64]="";
		char contraseña[64]="";
		cout<< "\tIngrese el nombre de usuario:  ";
		cin>>usuario;
		if (std::cin.fail()) { //comprabacion de erroes
			error_valor();
		}
		cout<< "\tIngrese la contrasena:  ";
		cin>>contraseña;
		if (std::cin.fail()) { //comprabacion de erroes
			error_valor();
		}

		if ((usuario!="") && (contraseña!="") ){
			menu(array_libros_has, array_libros_viv ,usuario, Pedido1);
		}
}

void menu(Producto array_libros_has[], Producto array_libros_viv[], char usuario[64], Pedido Pedido1){
	bool repite = true;
	int opcion;
	bool repertirinicio = true;	
	
	do {	
		system("cls");
		cout << "\x1B[1;97m" << "\n\t\t\t\t\tSales Management Dashboard - Santillana" << "\x1B[m \n";
		caratula();
		cout << "\x1B[1;97m" << "\n\t\tBIENVENIDO, " << usuario << "\x1B[m \n";
		cout << "\x1B[1;97m" << "\n\tMENU" << "\x1B[m \n";
		cout << "\x1B[1;97m" << "\n\t1. Catalogo" << "\x1B[m"<< "\n";
		cout << "\x1B[1;97m" << "\n\t2. Pedidos" << "\x1B[m"<< "\n";
		cout << "\x1B[1;97m" << "\n\t3. Canales de venta" << "\x1B[m"<< "\n";
		cout << "\x1B[1;97m" << "\n\t4. SALIR" << "\x1B[m"<< "\n";
		cout << "\x1B[1;97m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> opcion;
		
		if (std::cin.fail() || (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)) { //comprabacion de erroes
			error_valor();
		} else {
			switch (opcion){
				case 1:
					system("cls");
					catalogo(array_libros_has, array_libros_viv, Pedido1);
					break;
				   
				case 2:
					system("cls");
					pedidos(array_libros_has, array_libros_viv, Pedido1);
					break;
				case 3:
					system("cls");
					canales_de_venta(array_libros_has, array_libros_viv,Pedido1);
					break;

				case 4:
				   repite = false;
				   
				   break;			
			}
		}
	} while (repite);
}
	
void caratula(){
	char universidad[8] = "UCSP"; 
	char escuela[64] = "Escuela Profesional de Ciencia de la Computacion I"; 
	char curso[32] ="Ciencia de la Computacion I"; 
	char alumnos[64] = "Alumnos: \nIvan Matthias Sardon Medina \nAnthony Huicho Perez";
	char ciudad_año[32] = "Arequipa 2023 - II";
    cout << "\x1B[31;5;88m" << universidad<< "\x1B[m"<< "\n";
	cout << "\x1B[1;97m" << escuela << "\x1B[m"<< "\n";
	cout << curso << "\n";
	cout << "\x1B[1;97m" << alumnos<< "\x1B[m"<< "\n";
	cout << ciudad_año << "\n"; 
}

void catalogo(Producto array_libros_has[], Producto array_libros_viv[], Pedido Pedido1){
	bool retro =true;
	int op;
	system("cls");
	cout<<"\n\tCatalogo\n";
	cout << "\x1B[34m" << "\n\t1. Ingresar a catalogo 'HAS'" << "\x1B[m"<< "\n";
	cout << "\x1B[34m" << "\n\t2. Ingresar a catalogo 'vivo'" << "\x1B[m"<< "\n";
	cout << "\x1B[34m" << "\n\t3. Regresar" << "\x1B[m"<< "\n";
	cout << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
	cin >> op;
	if (std::cin.fail() || !(op >= 1 && op <=3)){
		error_valor();
		catalogo(array_libros_has,array_libros_viv, Pedido1);
	}else{
		switch (op){
			case 1:
				system("cls");
				cout << "\x1B[34m" << "\nCATALOGO Hasta agotar stock" << "\x1B[m"<< "\n\n";
				print_tabla_libros(array_libros_has);//catalogo HAS
				do{
					cout << "\x1B[34m" << "\n\t1. Regresar al Menu" << "\x1B[m"<< "\n";
					cout << "\x1B[34m" << "\n\t2. Regresar a Catalogo" << "\x1B[m"<< "\n";
					cout << "\x1B[34m" << "\n\t3. Ir a Pedidos" << "\x1B[m"<< "\n";
					
					cout << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
					cin >> op;
					if (std::cin.fail() || ((op != 1) && (op != 2) && (op != 3))){
						error_valor();
					} else {
						switch (op){
							case 1:
								retro= false;
								break;
							case 2:
								retro = false;
								catalogo(array_libros_has,array_libros_viv, Pedido1);
									
								break;
							case 3:
								retro= false;
								pedidos(array_libros_has, array_libros_viv, Pedido1);
								break;
						}
					}
				}while(retro);
				break;
			case 2:
				system("cls");
				cout << "\x1B[34m" << "\n\tCATALOGO Productos 'vivos'" << "\x1B[m"<< "\n\n";
				print_tabla_libros(array_libros_viv);//catalogo HAS
				do{
					cout << "\x1B[34m" << "\n\t1. Regresar al Menu" << "\x1B[m"<< "\n";
					cout << "\x1B[34m" << "\n\t2. Regresar a Catalogo" << "\x1B[m"<< "\n";
					cout << "\x1B[34m" << "\n\t3. Ir a Pedidos" << "\x1B[m"<< "\n";
					cout << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
					cin >> op;
					if (std::cin.fail() || ((op != 1) && (op != 2) && (op != 3))){
						error_valor();
					} else {
						switch (op){
							case 1:
								retro= false;
								break;
							case 2:
								retro = false;
								catalogo(array_libros_has, array_libros_viv, Pedido1);
								break;
							case 3:
								retro= false;
								pedidos(array_libros_has, array_libros_viv, Pedido1);
								break;
						}
					}
				}while(retro);
				break;
			case 3: 
				retro=false;
		}
	}
	cout<<"\n\n";
}
		