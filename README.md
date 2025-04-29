# 🖼️ Conversor de Imagens PPM (C)

Este projeto foi desenvolvido em linguagem C e tem como objetivo **ler arquivos de imagem no formato PPM (P3)** e aplicar transformações como:


- ✅ Conversão para preto e branco

- ✅ Conversão para tons de cinza

- ✅ Efeito negativo

- ✅ Efeito raio-x

- ✅ Efeito envelhecido (sépia)

- ✅ Rotação de 90 graus

- ✅ Rotação de 180 graus

- ✅ Salvamento com nome personalizado

---

## 📂 Como funciona

1. O usuário informa o **nome do arquivo de imagem PPM**.
2. O programa lê os dados RGB da imagem.
3. Aloca a imagem
4. Libera Imagem
5. Carrega imagem
6. aplica os efeitos desejados
8. Salva imagem

---


## 🧠 Tecnologias Utilizadas

- **Visual Studio Code**
      -extençao live share 
- **Linguagem:** C  
- **Formato de imagem:** PPM (P3)  
  *(Texto puro, fácil de manipular com `fscanf()` e `fprintf()`)*

---

## 🛠️ Como compilar e rodar

1. Compile o programa:

```bash
gcc main.c -o main.exe -lm
```

2. Execute:

```bash
./main.exe
```

3. Digite o nome do arquivo `.ppm` quando solicitado.

---

## ⚠️ Requisitos

- O arquivo PPM deve estar no **formato P3** (texto, não binário).
- O arquivo deve estar na **mesma pasta** do programa ou com o **caminho correto**.

---

## ✍️ Autor

Desenvolvido por **Guilherme Cavazzotto** e **Gabriel Vieria**


---


Guia de Consulta para Git Retirado de outro trablho 
## 📌 Git - Comandos Básicos

### 🔧 Configuração inicial

```bash
git config --global user.name "Seu Nome"
git config --global user.email "seu@email.com"
```

### 📁 Clonar um repositório

```bash
git clone https://github.com/usuario/nome-do-repo.git
```

### 📍 Ver status dos arquivos

```bash
git status
```

### ➕ Adicionar arquivos (para o stage)

```bash
git add .
# ou para adicionar um arquivo específico:
git add nome-do-arquivo.extensao
```

### 📝 Fazer um commit

```bash
git commit -m "mensagem explicando o que foi feito"
```

### 🔼 Enviar pro GitHub (push)

```bash
git push origin main
# se estiver em outro branch, substitua "main" pelo nome do branch
```

### 🔽 Puxar atualizações do GitHub (pull)

```bash
git pull origin main
```

### 🌿 Criar e mudar para um novo branch

```bash
git checkout -b nome-do-branch
```

### 🔁 Mudar para outro branch já existente

```bash
git checkout nome-do-branch
```

### 🔄 Ver todos os branches

```bash
git branch
```
