#Anne Caroline - 470124

palavras = []

def main():
  lerArquivo()
  #palavras é uma lista de string para que o HeapSort ordene é necessário transformar os números para inteiro
  elementos = [int(i) for i in palavras[1:]]
  heapsort(elementos)
  #para escrever no arquivo refaz o processo de string -> inteiro
  entrada = [str(i) for i in elementos]
  escreverArquivo(entrada)

def lerArquivo ():
  arquivo = open('entrada.data', 'r')

  #conteudo do arquivo é atribuido a uma lista
  for linha in arquivo:
     linha = linha.strip()
     palavras.append(linha)

  arquivo.close()

def escreverArquivo(entradas):
  arquivo = open('saida.data','w+')
  #adicionar o tamanho da entrada antes dos elementos ordenados
  arquivo.write(palavras[0])
  arquivo.write('\n')
  for aq in entradas:
    arquivo.write(aq)
    arquivo.write('\n')
  
  arquivo.close()

def heapsort(a):
    #troca os elementos da lista de posição
    def trocar(a,i,j):
        tmp = a[i]
        a[i] = a[j]
        a[j] = tmp
    #descobrir que é o maior(largest) elemento filho esquerdo(l) ou direito e realizar a troca de posições
    def peneira(a, i, size):
        l = 2*i+1
        r = 2*i+2
        largest = i
        if l <= size-1 and a[l] > a[i]:
            largest = l
        if r <= size-1 and a[r] > a[largest]:
            largest = r
        if largest != i:
            trocar(a, i, largest)
            peneira(a, largest, size)
    #montagem da heap máxima
    def construir(a, size):
        p = (size//2)-1
        while p>=0:
            peneira(a, p, size)
            p -= 1

    size = len(a)
    construir(a, size)
    end = size-1
    while(end > 0):
        trocar(a, 0, end)
        peneira(a, 0, end)
        end -= 1

if __name__ == '__main__':
   main()