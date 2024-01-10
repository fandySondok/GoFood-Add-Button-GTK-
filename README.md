# GoFood Add Button (GTK)

## Description

cuma pengen meniru tombol add item makanan di aplikasi gofood menggunakan GTK3. konsepnya hanya membuat 1 main container dan 2 child container yang berisi `add button` dan `spinbox` yang akan di `add` dan `remove` dalam main container tadi.

![Add Button](/docs/img/add-button.png?raw=true 'Add Button')
![Spin Box](/docs/img/spinbox.png?raw=true 'Spin Box')

## Prerequisites

- `gcc` (C Compiler)
- `gtk+3.0 library` (GTK Lib)

```sh
$ sudo apt-get update
$ sudo apt-get install build-essential
$ sudo apt-get install libgtk-3-dev
```

## Compiling

```bash
$ gcc main.c -o main `pkg-config --cflags --libs gtk+-3.0`
```

## Usage

```bash
$ ./main
```
