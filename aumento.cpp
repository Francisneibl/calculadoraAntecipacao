#include <stdio.h>
#include "aumento.h"

double aumento = 0;

double aumento_main(double total, float perda){

	float res = 0;
	aumento = 0;

	float taxa = (perda*100)/total;
//	aumento = taxa;

	while(res<=total){
		res = calculoaumentos(total,taxa);
	}

	return aumento;

}

double calculoaumentos(double total, float taxa){

	double res, res_final;

    aumento = aumento+000000.1;
	//res = total + ((total*aumento)/100);
	res = total +aumento;
	res_final = res - ((res*taxa)/100);



	return res_final;
}


double aumentoMoney (double total, double perda){

    double aumento2 = aumento_main(total,perda);

    //return total+(total*aumento2)/100;
    return total+aumento2;

}

double parcAumento (double total, int parcelas){

    return (float)total/parcelas;
}
