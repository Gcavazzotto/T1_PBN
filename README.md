🖼️ Conversor de Imagens PPM (C)

Este projeto foi desenvolvido em linguagem C e tem como objetivo ler arquivos de imagem no formato PPM (P3) e aplicar transformações como:

    ✅ Inversão horizontal da imagem

    ✅ Conversão para tons de cinza (preto e branco)

📂 Como funciona

    O usuário informa o nome do arquivo de imagem PPM.

    O programa lê os dados RGB da imagem.

    Aplica as transformações desejadas:

        Inversão horizontal

        Conversão para Preto e Branco (Tons de Cinza)

    Salva os novos arquivos com os seguintes nomes:

        nomeOriginal_invertido.ppm

        nomeOriginal_preto&branco.ppm

🧪 Exemplo

Se o usuário digitar:

golden.ppm

O programa irá gerar:

    golden_invertido.ppm → imagem invertida

    golden_preto&branco.ppm → imagem em tons de cinza

🧠 Tecnologias Utilizadas

    Linguagem: C

    Formato de imagem: PPM (P3)
    (Texto puro, fácil de manipular com fscanf() e fprintf())

🛠️ Como compilar e rodar

    Compile o programa:

gcc -o conversor conversor.c

Execute:

    ./conversor

    Digite o nome do arquivo .ppm quando solicitado.

⚠️ Requisitos

    O arquivo PPM deve estar no formato P3 (texto, não binário).

    O arquivo deve estar na mesma pasta do programa ou com o caminho correto.

✍️ Autor

Desenvolvido por Guilherme Cavazzotto
Contato: [opcional, se quiser colocar]
