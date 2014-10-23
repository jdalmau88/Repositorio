/*DALMAU CARMONA JOAN 47888347R*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
int wp=0,po=0;
int main(void){
	int n,i,j,l=0,m,s,w;
	double **a,*u,**g,tol,*x;
	int GaussOk=1;
	FILE * entrada ;
/*---------------------------------IMPORTANTE MODIFICAR EL NOMBRE ARCHIVO DEPENDIENDO DEL EJERCICIO QUE QUEREMOS REALIZAR----------------------------------------*/
	 entrada = fopen ( "ejercicio2a.dad","r" ); /* (1) */
	 if ( entrada == NULL ){
		printf ( " \n\n Error en obrir el fitxer \n\n" ); /* (2) */
		exit (1);
	}
	
	l = fscanf ( entrada," %le ", &tol);
	l = fscanf ( entrada," %d ", &n);

	/*
	printf("Doneu les dimensions de la matriu n = \n");
	scanf("%d",&n);

	printf("Quina tolerancia vols? (1e-3,1e-6,1e-9,1e-12) \n");
	scanf("%le",&tol);*/

	printf("Elige una opcion:\n1. Hacer gauss o buscar inversa:\n2. Usar el metodo de la potencia");
	scanf("%d",&s);
	
	
	if (s==1){
		/*printf("Doneu les dimensions de la matriu g = \n");*/
		l = fscanf ( entrada," %d ", &m);
		/*scanf("%d",&m);*/
	}
	else if (s==2){
		m==1;
	}
  
	a = (double  **)malloc( n*sizeof(double *) );
	if ( a == NULL ){
		printf("No hi ha prou memoria");
		exit(1);
	}
	for (i = 0; i < n; i++){
		a[i] = (double  *)malloc( n*sizeof(double ) );
		if ( a[i] == NULL ){
			printf("No hi ha prou memoria");
			exit(2);
		}
	}

	
	g = (double  **)malloc( n*sizeof(double *) );
	if ( g == NULL ){
		printf("No hi ha prou memoria");
		exit(1);
	}
	for (i = 0; i < n; i++){
		g[i] = (double  *)malloc( m*sizeof(double ) );
		if ( g[i] == NULL ){
			printf("No hi ha prou memoria");
			exit(2);
		}
	}
	
	
	u = (double  *)malloc( n*sizeof(double ) );
	if ( u == NULL){
		printf("No hi ha prou memoria");
		exit(3);
	}
	
	
	x = (double  *)malloc( n*sizeof(double ) );
	if ( x == NULL){
		printf("No hi ha prou memoria");
		exit(3);
	}
	
	

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			l = fscanf ( entrada," %le ", &a[i][j]);
			/*scanf("%le", &a[i][j]);*/
		}
	}
	
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			l = fscanf ( entrada," %le ", &g[i][j]);
			/*scanf("%le", &g[i][j]);*/
		}
	}
	fclose ( entrada );
	
	printf("La matriu A = \n");
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf(" %e",a[i][j]);
		}
		printf("\n");
	}

	printf("La matriu G = \n");
	for (i = 0; i < n; i++){
		for (j = 0; j <m; j++){
			printf(" %e",g[i][j]);
		}
		printf("\n");
	}
	
	for (i = n-1; i >= 0; i--){
		for (j = i-1; j >= 0; j--){
			if (a[i][j]!=0)
			GaussOk=0;  
		}
	 }

	if(s==1){
		if (GaussOk==0){
		  po=1;
			l=gauss(a,g,n,m,tol);  
		}
		else if(m==1){
			for (w = 0; w < n; w++){
				u[w]=g[w][0];
			}
			l=resoltrisup(n,a,u,x,tol);
		}
		else 
		printf ("\n Matriz incorrecta! ");
	
		if(l==1)
			printf ("\n Error en la Tolerancia!\n \n  ");
		else if(l==0)
			printf ("\n Todo Ok! \n \n  ");
	}
	else if(s==2){
		l=potencia(a,n,tol);
		if(l==1)
			printf ("\n NO ha habido convergencia!\n \n  ");
		else if(l==0)
			printf ("\n Todo Correcto!! \n \n  ");
	}
	else
		printf("\n Error opcion incorrecta elige opcion 1 o 2 \n ");
  
	return 0;

}

int gauss(double **A, double **G, int n ,int m, double tol){
	  int i,j,s,w,l=0,inversa=1;  
	  double *B,**CopiaA,division,*x,**h,**u;

	  
	  
	  
	  
	  
	  h = (double  **)malloc( n*sizeof(double *) );
	if ( h == NULL ){
		printf("No hi ha prou memoria");
		exit(1);
	}
	for (i = 0; i < n; i++){
		h[i] = (double  *)malloc( n*sizeof(double ) );
		if ( h[i] == NULL ){
			printf("No hi ha prou memoria");
			exit(2);
		}
	}
	  
	  
	u= (double  **)malloc( n*sizeof(double *) );
	if ( u == NULL ){
		printf("No hi ha prou memoria");
		exit(1);
	}
	for (i = 0; i < n; i++){
		u[i] = (double  *)malloc( n*sizeof(double ) );
		if ( u[i] == NULL ){
			printf("No hi ha prou memoria");
			exit(2);
		}
	}  
	  
	  
	  
	  
	  
	  
	  
	  

	x = (double  *)malloc( n*sizeof(double ) );
	if ( x == NULL){
		printf("No hi ha prou memoria");
		exit(3);
	}
	
	  CopiaA = (double  **)malloc( n*sizeof(double *) );
	  B = (double  *)malloc( n*sizeof(double ) );

	if ( B == NULL){
		 printf("No hi ha prou memoria");
		exit(3);
	}
	if ( CopiaA == NULL ){
		printf("No hi ha prou memoria");
		exit(1);
	}
	for (i = 0; i < n; i++){
		CopiaA[i] = (double  *)malloc( n*sizeof(double ) );
		if ( CopiaA[i] == NULL ){
			printf("No hi ha prou memoria");
			exit(2);
		}
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){				
			h[i][j]=0;  
			u[i][j]=0;
		}
	}
	for (i = 0; i < n; i++){
		h[i][i]=1;
	}
	
	for (i = 0; i < n; i++){
		u[i][i]=A[i][i];
	}
	if (m==n){
		for (i = n-1; i >= 0; i--){
			for (j = i-1; j >= 0; j--){
				if (G[i][j]!=0)
					inversa=0;  
	
			}
		}
		for (j = i-1; j >= 0; j--){
			for (i = n-1; i >= 0; i--){
				if (G[i][j]!=0)
					inversa=0;      
			}
		}
	} 
	if (inversa==0 || m!=n){
		for (s= 0; s < n-1; s++){ 
			for (i = s; i < n-1; i++){ 
				division=A[i+1][s]/A[s][s];
				printf("%e=%e / %e",division,A[i+1][s],A[s][s]);
				if (i>=s)
				h[i+1][s]=division; 
				for (j = 0; j < n; j++){
					A[i+1][j]=A[i+1][j]-division*A[s][j];  
					/*G[i+1][w]=G[i+1][w]-division*G[s][w];*/
					
					
				if(fabs(A[i+1][j])<tol)
					A[i+1][j]=0;
					/*if(fabs(A[i+1][j])<tol)
					A[i+1][j]=0;*/
					/*printf ("matrix: %e",A[i+1][j]);*/
					
				}
				for (w = 0; w <m; w++) 
					G[i+1][w]=G[i+1][w]-division*G[s][w];
			
				/*for (w = 0; w <p; w++) */
					
				
					
			}
		}
		printf("\nLa matriu A = \n");
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				printf(" %e",A[i][j]);
				if (j>i)
				  u[i][j]=A[i][j];
			}
			printf("\n");
		}
		printf("\nLa matriu L = \n");
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				printf(" %e",h[i][j]);
			}
			printf("\n");
		}
		printf("\nLa matriu U = \n");
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				printf(" %e",u[i][j]);
			}
			printf("\n");
		}
		printf("Vector G\n");
		for (i = 0; i<n; i++){
			for (j = 0; j < m; j++)
				printf("%e",G[i][j]);
			printf("\n");
		}
		for (j = 0; j < m; j++){
			for (w = 0; w < n; w++){
				B[w]=G[w][j];
					for (i = 0; i<n; i++){
						CopiaA[w][i]=A[w][i];
					}
			
			}
			l=resoltrisup(n,CopiaA,B,x,tol);
		}
		return l;
	}
	else{
	  
	  
		printf("Inversa:");
 
		for (s= 0; s < n-1; s++){ 
			 for (i = s; i < n-1; i++){ 
				division=A[i+1][s]/A[s][s];
					for (j = 0; j < n; j++){
						A[i+1][j]=A[i+1][j]-division*A[s][j];   
						G[i+1][j]=G[i+1][j]-division*G[s][j]; 
						if(fabs(A[i+1][j])<tol)
							 A[i+1][j]=0;
						/*if(fabs(G[i+1][j])<tol)
							G[i+1][j]=0;*/
					}
			}
		}

		for (s= n-1; s >=0 ; s--){ 
			for (i = s; i>0; i--){ 
				division=A[i-1][s]/A[s][s];
				for (j =n-1; j>=0 ; j--){
					G[i-1][j]=G[i-1][j]-division*G[s][j];
					A[i-1][j]=A[i-1][j]-division*A[s][j]; 
				if(fabs(A[i-1][j])<tol)
					A[i-1][j]=0;
				if(fabs(G[i-1][j])<tol)
					G[i-1][j]=0;
						 /*  }  */

				}
			}
		}
	      
	      
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				G[i][j]=G[i][j]/A[i][i];
			}
			A[i][i]=A[i][i]/A[i][i];
		}

		printf("Inversa: = \n");
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				printf(" %e",G[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		
		if (po!=1)
		potencia(G,n,tol);


		return l;

	}
}

int resoltrisup(int n,double **a,double *u,double *x,double tol){
 
	 int i,j,s,valor=0;
	/* double *x1;

	
	x1 = (double  *)malloc( n*sizeof(double ) );*/

	printf("\n");

	for (i = n-1; i >= 0; i--){

		for (j = n-1; j > 0; j--){
			while (a[i][j-1]!=0 &&  j!=0){
				u[i]=u[i]-a[i][j];
				/*printf ("%e\n\n",u[i][0]);*/
				j--;
			}

			if (a[j][j-1]==0 || (i==0 && j==0)){

				if(fabs(a[i][i])<tol)
					return 1;
				printf ("%e=%e/%e\n", x[valor],u[i],a[i][i]);
				x[valor]=u[i]/a[i][i];  
				for (s = i; s >= 0; s--){
					a[s][i]=x[valor]*a[s][i];
					j=0;
				}

				valor++;
			}
		}
	}
	printf("\n");
	po=po+1;
	for (valor = 0; valor < n; valor++){
		printf("Los valores de la matriz %d  son:  x%d..: %e -- \n",po,valor,x[valor]);
	}
	return 0;
}

int potencia(double **A, int n, double tol){
	double *u,*v,modulo,**g,prec=0.0001;
	int i,j,nummulti,iter;

	if (wp!=1){
		  printf("\n\n Indica el valor de la Iterados que desea usar para el vap maximo(1,2,3...n)\n\n");
		  scanf("%d",&iter);
	}
	else {
		  printf("\n\n Indica el valor de la Iterados que desea usar para el vap minimo(1,2,3...n)\n\n");
		  scanf("%d",&iter);
	}
	
	v = (double  *)malloc( n*sizeof(double ) );
	u = (double  *)malloc( n*sizeof(double ) );
	g = (double  **)malloc( n*sizeof(double *) );
	if ( g == NULL ){
		printf("No hi ha prou memoria");
		exit(1);
	}
	for (i = 0; i < n; i++){
		g[i] = (double  *)malloc( n*sizeof(double ) );
		if ( g[i] == NULL ){
			printf("No hi ha prou memoria");
			exit(2);
		}
	}
	
	/*printf("La matriu A = \n");
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf(" %e",A[i][j]);
		}
		printf("\n");
	}*/
	
	for (i =0; i < n; i++){
		for (j =0; j < n; j++){
			if(i==j)
				g[i][j]=1;
			else
				g[i][j]=0; 
		}
	}
	/*u[0]=1;*/
	for (i =0; i < n; i++){
		u[i]=1;  
	}
	for (nummulti = 0; nummulti  < iter ; nummulti  ++){
		for (i =0; i < n; i++){
			v[i]=0;
		}
		for (i = 0; i < n ; i ++){
			for (j=0; j < n ; j ++){
				v[i]=v[i]+(A[i][j]*u[j]);  
			}
		}
		modulo=0;
		for (j=0; j < n ; j ++)
			modulo=modulo+(v[j]*v[j]);
		modulo=sqrt(modulo);
		if(nummulti<iter-1){
			for (i = 0; i < n ; i ++)
				v[i]=v[i]/modulo; 
			for (i =0; i < n; i++){
					  u[i]=v[i];
			}
		}
		
	}
	for (i =0; i < n; i++)
		  v[i]=v[i]/u[i]; 
	
	
	
	if (wp!=1){
		printf ( "Els vap maximo es: \n " );
		printf ( "  %e \n \n" ,  v [ 1 ]);
		if (fabs(v[1]-v [0])> prec)
			  return 1;
		wp++;
		gauss(A,g,n,n,tol);
	}
	else{
	   printf ( "Els vap minimo es: \n " );
	      printf ( "  %e \n \n" ,  v [ 1 ]);
	}
	return 0;
	
}
