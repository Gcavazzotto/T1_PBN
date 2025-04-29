
//Desenvolvido por **Guilherme Cavazzotto** e **Gabriel Vieria**
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int largura, altura;
    int **R, **G, **B;
} Imagem;



//exemplo de maloc 
//int *p = malloc(10 * sizeof(int));

void alocarImagem(Imagem *img) {
    img->R = malloc(img->altura * sizeof(int *)); //cria um vetor de ponteiros (um vetor de linhas).
    img->G = malloc(img->altura * sizeof(int *));
    img->B = malloc(img->altura * sizeof(int *));
    for (int i = 0; i < img->altura; i++) {
        img->R[i] = malloc(img->largura * sizeof(int));
        img->G[i] = malloc(img->largura * sizeof(int));
        img->B[i] = malloc(img->largura * sizeof(int));
    }
}

void liberarImagem(Imagem *img) {// Em C, toda memória que você aloca com malloc precisa ser liberada manualmente com free.
   // Se não liberar, acontece vazamento de memória (o programa vai consumindo mais e mais RAM desnecessariamente).
    for (int i = 0; i < img->altura; i++) {
        free(img->R[i]);
        free(img->G[i]);
        free(img->B[i]);
    }
    free(img->R);
    free(img->G);
    free(img->B);
}

void carregarImagem(const char *nome, Imagem *img) {
    FILE *arquivo = fopen(nome, "r");
    if (!arquivo) {
        printf("Erro ao abrir a imagem.\n");
        exit(1);
    }

    char formato[3];
    fscanf(arquivo, "%s", formato);
    fscanf(arquivo, "%d %d", &img->largura, &img->altura);
    int max;
    fscanf(arquivo, "%d", &max);

    alocarImagem(img);

    for (int j = 0; j < img->altura; j++) {
        for (int i = 0; i < img->largura; i++) {
            fscanf(arquivo, "%d %d %d", &img->R[j][i], &img->G[j][i], &img->B[j][i]);
        }
    }

    fclose(arquivo);
}

void salvarImagem(const char *nome, Imagem *img) {
    FILE *arquivo = fopen(nome, "w");
    fprintf(arquivo, "P3\n%d %d\n255\n", img->largura, img->altura);
    for (int j = 0; j < img->altura; j++) {
        for (int i = 0; i < img->largura; i++) {
            fprintf(arquivo, "%d %d %d ", img->R[j][i], img->G[j][i], img->B[j][i]);
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
}

void efeitoNegativo(Imagem *img) {
    for (int j = 0; j < img->altura; j++) {
        for (int i = 0; i < img->largura; i++) {
            img->R[j][i] = 255 - img->R[j][i];
            img->G[j][i] = 255 - img->G[j][i];
            img->B[j][i] = 255 - img->B[j][i];
        }
    }
}

void efeitoRaioX2(Imagem *img) {
    for (int i = 0; i < img->altura; i++) {
        for (int j = 0; j < img->largura; j++) {
            int r = img->R[i][j];
            int g = img->G[i][j];
            int b = img->B[i][j];

            // Primeiro converte para cinza usando média ponderada
            int cinza = (int)(0.299 * r + 0.587 * g + 0.114 * b);

            // Depois faz o negativo desse cinza
            int raioX = 255 - cinza; // Aqui, 255 é o valor máximo

            // Aplica o raioX igual nos três canais
            img->R[i][j] = raioX;
            img->G[i][j] = raioX;
            img->B[i][j] = raioX;
        }
    }
}

void efeitoRaioX(Imagem *img) {
    float fator = 1.5; // Pode ajustar entre 1.0 e 2.0

    for (int j = 0; j < img->altura; j++) {
        for (int i = 0; i < img->largura; i++) {
            // Converter para tons de cinza
            float cinza = img->R[j][i] * 0.299 + img->G[j][i] * 0.587 + img->B[j][i] * 0.114;

            // 2. Aplicar transformação de intensidade
            float raioX = pow(cinza, fator);

            // Normalizar para não estourar (garante que fique até 255)
            if (raioX > 255) raioX = 255;

            // Aplicar o mesmo valor nos três canais
            img->R[j][i] = img->G[j][i] = img->B[j][i] = (int)raioX;
        }
    }
}

void efeitoEnvelhecida(Imagem *img) {
    float fator = 0.1;
    for (int j = 0; j < img->altura; j++) {
        for (int i = 0; i < img->largura; i++) {
            int r = img->R[j][i];
            int g = img->G[j][i];
            int b = img->B[j][i];

            r = r * (1 + fator) + 10;
            g = g * (1 + fator) + 10;
            b = b * (1 - fator) - 10;

            if (r > 255) r = 255;
            if (g > 255) g = 255;
            if (b < 0) b = 0;

            img->R[j][i] = r;
            img->G[j][i] = g;
            img->B[j][i] = b;
        }
    }
}

void rotacionarImagem(Imagem *img) {
    int novaAltura = img->largura;
    int novaLargura = img->altura;

    int **R_temp = malloc(novaAltura * sizeof(int *));
    int **G_temp = malloc(novaAltura * sizeof(int *));
    int **B_temp = malloc(novaAltura * sizeof(int *));

    for (int i = 0; i < novaAltura; i++) {
        R_temp[i] = malloc(novaLargura * sizeof(int));
        G_temp[i] = malloc(novaLargura * sizeof(int));
        B_temp[i] = malloc(novaLargura * sizeof(int));
    }

    for (int j = 0; j < img->altura; j++) {
        for (int i = 0; i < img->largura; i++) {
            R_temp[i][novaLargura - 1 - j] = img->R[j][i];
            G_temp[i][novaLargura - 1 - j] = img->G[j][i];
            B_temp[i][novaLargura - 1 - j] = img->B[j][i];
        }
    }

    liberarImagem(img);

    img->largura = novaLargura;
    img->altura = novaAltura;
    img->R = R_temp;
    img->G = G_temp;
    img->B = B_temp;
}

void rotacionar180(Imagem *img) {
    for (int j = 0; j < img->altura / 2; j++) {
        for (int i = 0; i < img->largura; i++) {
            int inv_j = img->altura - 1 - j;
            int inv_i = img->largura - 1 - i;

            int tempR = img->R[j][i];
            int tempG = img->G[j][i];
            int tempB = img->B[j][i];

            img->R[j][i] = img->R[inv_j][inv_i];
            img->G[j][i] = img->G[inv_j][inv_i];
            img->B[j][i] = img->B[inv_j][inv_i];

            img->R[inv_j][inv_i] = tempR;
            img->G[inv_j][inv_i] = tempG;
            img->B[inv_j][inv_i] = tempB;
        }
    }
}

void efeitoPretoBranco(Imagem *img) {
    for (int j = 0; j < img->altura; j++) {
        for (int i = 0; i < img->largura; i++) {
            int media = (img->R[j][i] + img->G[j][i] + img->B[j][i]) / 3;
            int valor = (media > 127) ? 255 : 0;
            img->R[j][i] = img->G[j][i] = img->B[j][i] = valor;
        }
    }
}
//matriz[j][i] = (r*0.299)+(g*0.587)+(b*0.114);
void efeitoTonsDeCinza(Imagem *img) {
    for (int j = 0; j < img->altura; j++) {
        for (int i = 0; i < img->largura; i++) {
            int cinza = (int)(img->R[j][i] * 0.299 + img->G[j][i] * 0.587 + img->B[j][i] * 0.114);
            img->R[j][i] = img->G[j][i] = img->B[j][i] = cinza;
        }
    }
}

int main() {
    Imagem img;
    char nomeArquivo[100];

    printf("Digite o nome da imagem .ppm para abrir: ");
    scanf("%s", nomeArquivo);

    carregarImagem(nomeArquivo, &img);

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
        printf("8. Salvar imagem\n");
        printf("9. Girar 180 graus\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: efeitoNegativo(&img); break;
            case 2: efeitoRaioX(&img); break;
            case 3: efeitoRaioX2(&img); break;
            case 4: efeitoEnvelhecida(&img); break;
            case 5: rotacionarImagem(&img); break;
            case 6: efeitoPretoBranco(&img); break;
            case 7: efeitoTonsDeCinza(&img); break;
            case 8: {
                char nomeSaida[100];
                printf("Digite o nome do arquivo de saída (ex: resultado.ppm): ");
                scanf("%s", nomeSaida);
                salvarImagem(nomeSaida, &img);
                printf("Imagem salva com sucesso!\n");
                break;
            }
            case 9: rotacionar180(&img); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    liberarImagem(&img);
    return 0;
}
