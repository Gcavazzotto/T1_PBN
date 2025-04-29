//Desenvolvido por **Guilherme Cavazzotto** e **Gabriel Vieria**

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void alocarImagem(int ***R, int ***G, int ***B, int largura, int altura) {
    *R = malloc(altura * sizeof(int *));
    *G = malloc(altura * sizeof(int *));
    *B = malloc(altura * sizeof(int *));
    for (int i = 0; i < altura; i++) {
        (*R)[i] = malloc(largura * sizeof(int));
        (*G)[i] = malloc(largura * sizeof(int));
        (*B)[i] = malloc(largura * sizeof(int));
    }
}

void liberarImagem(int **R, int **G, int **B, int altura) {
    for (int i = 0; i < altura; i++) {
        free(R[i]);
        free(G[i]);
        free(B[i]);
    }
    free(R);
    free(G);
    free(B);
}

//EXEMPLO SOR 
//-----------------------------------------------------------------------
/*FILE *fp;
    
  	fp = fopen("golden.ppm","r");
	if(fp==NULL){
		printf("Erro ao abrir o arquivo!");
		}
  	char tipoImg[3];

  	int i, j, linha, coluna, val, r, g, b;
  	
  	fscanf(fp, "%s", tipoImg); // le o tipo de imagem P3 (color), P2 (P&B) 
  	printf("%s\n", tipoImg);
  	
  	fscanf(fp, "%d %d", &coluna, &linha); // le o tamanho da matriz  
  	printf("%d %d\n", coluna, linha);

  	int matriz[700][700];
  	
  	fscanf(fp, "%d", &val); // le o valor maximo. 
  	printf("%d\n", val);

	for(j=0; j<linha; j++)
	{
		for(i=0; i<coluna; i++)
		{  	
  			fscanf(fp, "%d %d %d", &r, &g, &b);
		  	//printf("%d %d %d\n", r, g, b);
		  	matriz[j][i] = ((r*0.30)+(g*0.59)+(b*0.11));
		  	//printf("%d\n", matriz[j][i]);
		}
	}
	printf("leu todo o arquivo e gerou vetor p&b\n");
  	fclose(fp);*/




void carregarImagem(const char *nome, int ***R, int ***G, int ***B, int *largura, int *altura) {
    FILE *arquivo = fopen(nome, "r");
    if (!arquivo) {
        printf("Erro ao abrir imagem.\n");
        exit(1);
    }

    char formato[3];
    fscanf(arquivo, "%s", formato);
    fscanf(arquivo, "%d %d", largura, altura);
    int max;
    fscanf(arquivo, "%d", &max);

    alocarImagem(R, G, B, *largura, *altura);

    for (int j = 0; j < *altura; j++) {
        for (int i = 0; i < *largura; i++) {
            fscanf(arquivo, "%d %d %d", &(*R)[j][i], &(*G)[j][i], &(*B)[j][i]);
        }
    }

    fclose(arquivo);
}

void salvarImagem(const char *nome, int **R, int **G, int **B, int largura, int altura) {
    FILE *arquivo = fopen(nome, "w");
    fprintf(arquivo, "P3\n%d %d\n255\n", largura, altura);
    for (int j = 0; j < altura; j++) {
        for (int i = 0; i < largura; i++) {
            fprintf(arquivo, "%d %d %d ", R[j][i], G[j][i], B[j][i]);
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
}

void efeitoNegativo(int **R, int **G, int **B, int largura, int altura) {
    for (int j = 0; j < altura; j++)
        for (int i = 0; i < largura; i++) {
            R[j][i] = 255 - R[j][i];
            G[j][i] = 255 - G[j][i];
            B[j][i] = 255 - B[j][i];
        }
}

void efeitoRaioX(int **R, int **G, int **B, int largura, int altura) {
    for (int j = 0; j < altura; j++) {
        for (int i = 0; i < largura; i++) {
            float cinza = R[j][i]*0.299 + G[j][i]*0.587 + B[j][i]*0.114;
            float raioX = pow(cinza, 1.5);
            if (raioX > 255) raioX = 255;
            R[j][i] = G[j][i] = B[j][i] = (int)raioX;
        }
    }
}

void efeitoRaioX2(int **R, int **G, int **B, int largura, int altura) {
    for (int j = 0; j < altura; j++) {
        for (int i = 0; i < largura; i++) {
            int cinza = (int)(0.299 * R[j][i] + 0.587 * G[j][i] + 0.114 * B[j][i]);
            int raioX = 255 - cinza;
            R[j][i] = G[j][i] = B[j][i] = raioX;
        }
    }
}

void efeitoEnvelhecida(int **R, int **G, int **B, int largura, int altura) {
    float fator = 0.1;
    for (int j = 0; j < altura; j++) {
        for (int i = 0; i < largura; i++) {
            int r = R[j][i] * (1 + fator) + 10;
            int g = G[j][i] * (1 + fator) + 10;
            int b = B[j][i] * (1 - fator) - 10;

            if (r > 255) r = 255;
            if (g > 255) g = 255;
            if (b < 0) b = 0;

            R[j][i] = r;
            G[j][i] = g;
            B[j][i] = b;
        }
    }
}

void rotacionarImagem(int ***R, int ***G, int ***B, int *largura, int *altura) {
    int novaAltura = *largura;
    int novaLargura = *altura;

    int **R_temp, **G_temp, **B_temp;
    alocarImagem(&R_temp, &G_temp, &B_temp, novaLargura, novaAltura);

    for (int j = 0; j < *altura; j++) {
        for (int i = 0; i < *largura; i++) {
            R_temp[i][novaLargura - 1 - j] = (*R)[j][i];
            G_temp[i][novaLargura - 1 - j] = (*G)[j][i];
            B_temp[i][novaLargura - 1 - j] = (*B)[j][i];
        }
    }

    liberarImagem(*R, *G, *B, *altura);

    *largura = novaLargura;
    *altura = novaAltura;
    *R = R_temp;
    *G = G_temp;
    *B = B_temp;
}

void rotacionar180(int **R, int **G, int **B, int largura, int altura) {
    for (int j = 0; j < altura / 2; j++) {
        for (int i = 0; i < largura; i++) {
            int inv_j = altura - 1 - j;
            int inv_i = largura - 1 - i;

            int tempR = R[j][i];
            int tempG = G[j][i];
            int tempB = B[j][i];

            R[j][i] = R[inv_j][inv_i];
            G[j][i] = G[inv_j][inv_i];
            B[j][i] = B[inv_j][inv_i];

            R[inv_j][inv_i] = tempR;
            G[inv_j][inv_i] = tempG;
            B[inv_j][inv_i] = tempB;
        }
    }
}

void efeitoPretoBranco(int **R, int **G, int **B, int largura, int altura) {
    for (int j = 0; j < altura; j++) {
        for (int i = 0; i < largura; i++) {
            int media = (R[j][i] + G[j][i] + B[j][i]) / 3;
            int valor = (media > 127) ? 255 : 0;
            R[j][i] = G[j][i] = B[j][i] = valor;
        }
    }
}

void efeitoTonsDeCinza(int **R, int **G, int **B, int largura, int altura) {
    for (int j = 0; j < altura; j++) {
        for (int i = 0; i < largura; i++) {
            int cinza = (int)(R[j][i] * 0.299 + G[j][i] * 0.587 + B[j][i] * 0.114);
            R[j][i] = G[j][i] = B[j][i] = cinza;
        }
    }
}

int main() {
    int **R, **G, **B;
    int largura, altura;
    char nomeArquivo[100];

    printf("Digite o nome da imagem .ppm para abrir: ");
    scanf("%s", nomeArquivo);

    carregarImagem(nomeArquivo, &R, &G, &B, &largura, &altura);

    int opcao;
    do {
        printf("\nMenu de opções:\n");
        printf("1. Efeito negativo\n");
        printf("2. Efeito raio-X\n");
        printf("3. Efeito raio-X2\n");
        printf("4. Efeito envelhecida\n");
        printf("5. Girar 90 graus\n");
        printf("6. Efeito preto e branco\n");
        printf("7. Efeito tons de cinza\n");
        printf("8. Girar 180 graus\n");
        printf("9. Salvar Imagem\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: efeitoNegativo(R, G, B, largura, altura); break;
            case 2: efeitoRaioX(R, G, B, largura, altura); break;
            case 3: efeitoRaioX2(R, G, B, largura, altura); break;
            case 4: efeitoEnvelhecida(R, G, B, largura, altura); break;
            case 5: rotacionarImagem(&R, &G, &B, &largura, &altura); break;
            case 6: efeitoPretoBranco(R, G, B, largura, altura); break;
            case 7: efeitoTonsDeCinza(R, G, B, largura, altura); break;
            case 9: {
                char nomeSaida[100];
                printf("Digite o nome do arquivo de saída: ");
                scanf("%s", nomeSaida);
                salvarImagem(nomeSaida, R, G, B, largura, altura);
                printf("Imagem salva com sucesso!\n");
                break;
            }
            case 8: rotacionar180(R, G, B, largura, altura); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    liberarImagem(R, G, B, altura);
    return 0;
}
