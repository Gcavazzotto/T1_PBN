# 🖼️ Conversor de Imagens PPM (C)

Este projeto foi desenvolvido em linguagem C e tem como objetivo **ler arquivos de imagem no formato PPM (P3)** e aplicar transformações como:

- ✅ Inversão horizontal da imagem  
- ✅ Conversão para tons de cinza (preto e branco)

---

## 📂 Como funciona

1. O usuário informa o **nome do arquivo de imagem PPM**.
2. O programa lê os dados RGB da imagem.
3. Aplica as transformações desejadas:
   - Inversão horizontal
   - Conversão para Preto e Branco (Tons de Cinza)
4. Salva os novos arquivos com os seguintes nomes:
   - `nomeOriginal_invertido.ppm`
   - `nomeOriginal_preto&branco.ppm`

---

## 🧪 Exemplo

Se o usuário digitar:

```bash
golden.ppm
```

O programa irá gerar:

- `golden_invertido.ppm` → imagem invertida  
- `golden_preto&branco.ppm` → imagem em tons de cinza

---

## 🧠 Tecnologias Utilizadas

- **Linguagem:** C  
- **Formato de imagem:** PPM (P3)  
  *(Texto puro, fácil de manipular com `fscanf()` e `fprintf()`)*

---

## 🛠️ Como compilar e rodar

1. Compile o programa:

```bash
gcc -o conversor conversor.c
```

2. Execute:

```bash
./conversor
```

3. Digite o nome do arquivo `.ppm` quando solicitado.

---

## ⚠️ Requisitos

- O arquivo PPM deve estar no **formato P3** (texto, não binário).
- O arquivo deve estar na **mesma pasta** do programa ou com o **caminho correto**.

---

## ✍️ Autor

Desenvolvido por **Guilherme Cavazzotto**  
Contato: [opcional]

---

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
