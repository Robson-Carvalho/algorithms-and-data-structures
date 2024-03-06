# Desvendando o Big O Notation

Quando trabalhamos com algoritmos e estruturas de dados, estamos buscando reduzir a complexidade de tempo e espaço dentro do algoritmo, escolhendo sempre as melhores estruturas ee técnicas para performar nossos algoritmos. Mas como medimos a performance dos nossos algoritmos? Utilizando **análise assintótica**

### Análise Assintótica

Uma forma de medir a performance de um algoritmo conforme a quantidade de dados recebida. Basicamente, queremos saber a quantidade de operações ao logo do crescimento do tamanho do input, ou seja, quanto um algoritmo escala ao receber quantidades maiores e maiores de entrada.

#### Análise da função Two Sum

```go
	func TwoSum(nums []int, target int) []int {
		hash := make(map[int]int)

		for i, num := range nums {
			complement := target - num

			if index, exists := hash[complement]; exists {
				return []int{i, index}
			}
			hash[num] = i
		}

		return []int{}
}

```

A função acima tem um comportamento que chamos de **Linear**, já que a mesma cresce conforme o tamanho do input, mas como definimos se um algoritmo é linear ou não? Vamos descobrir a seguir:

##### Análise completa do algoritmo:

```go
	func TwoSum(nums []int, target int) []int {
		hash := make(map[int]int) // -> 1

		for i, num := range nums { // -> (n) len(n)
			complement := target - num // -> 1

			if index, exists := hash[complement]; exists { // -> 1
				return []int{i, index} // -> 1
			}
			hash[num] = i // -> 1
		}

		return []int{} // -> 1
}
```

Agora vamos tranformar a análise acima em uma fórmula/função para descobrirmos a complexidade do algoritmo.

```bash
O = 1 + (n * 1 * (1 * 1) * 1) + 1
O = 1 + n + 1
O = n + 2
```

Chegamos a conclusão que O é igual a n + 2. Dessa forma, chegamos na análise assintótica do algoritmo/função Two Sum que é a fórmula a seguir:

```bash
O(n+2)
```

Agora vamos fazer algumas operações com a fórmula encontrada para entendermos melhor o crescimento das operações ao decorrer do crescimento do tamanho do input (n).

Se o tamanho do input for igual a 100, ou seja, n = 100, vamos ter a seguinte expressão:

```bash
O(n+2) => O(100+2) = 102
```

Se o tamanho do input for igual a 1000, ou seja, n = 1000, vamos ter a seguinte expressão:

```bash
O(n+2) => O(1000+2) = 1002
```

Se o tamanho do input for igual a 100.000, ou seja, n = 100.000, vamos ter a seguinte expressão:

```bash
O(n+2) => O(100.000+2) = 100.002
```

Se o tamanho do input for igual a 100.000.000.000, ou seja, n = 100.000.000.000, vamos ter a seguinte expressão:

```bash
O(n+2) => O(100.000.000.000+2) = 100.000.000.002
```

Podemos perceber que quanto maior for o tamanho do input (n) mais irrelevante fica o número 2 na expressão? Já que comparado ao milhão e ao trilhão, o número 2 é muito irrelevante. Então, quando construirmos fizermos uma análise de um algoritmo para determinar uma fórmula para o mesmo, o que vai nos servir é o maior termo, logo:

```bash
O(n+2) => O(n) => [Linear]
```

Dessa forma, o que importa é o maior termo já que é o que faz o algoritmo escalar ou não.

#### Gráfico de um algoritmo Linear O(n)

![Gráfico de um algoritmo Linear O(n)](https://res.cloudinary.com/practicaldev/image/fetch/s--gq0tGoAm--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://miro.medium.com/max/640/1%2AX5JanH7K1HPOarB4fJpTTg.png)
<br>
[Eduardo Rabelo](https://dev.to/oieduardorabelo/os-fundamentos-da-notacao-big-o-1jbp)

Agora que entendermos como realizar a análise assintótica de um algoritmo e descobrimos como funciona um algorimto de Big O linear, vamos partir para outros exemplos, como o quadrático.

### Notação Big O Quadrático ou O(n²)

```go
func superSumNumbers(arr []int) int {
	sum := 0 // -> 1

	for i := 0; i < len(arr); i++ { // -> len(n) (n)
		for j := 0; j < len(arr); j++ { // -> len(n) (n)
			sum += arr[i] // -> 1
			sum += arr[i] // -> 1
		}
	}

	return sum // -> 1
}
```

Para compreendermos o comportamento quadrático de um algoritmo, vamos analisar a função "superSumNumbers" acima. Podemos notar acima que temos dois for aninhados que percorrem o mesmo array e isso é uma característica de um algoritmo com comportamento quadrático, **mas vale resaltar que não se aplica para todos os algoritmos, já que podemos ter dois for aninhados onde um percorre outro array**. No entanto, sempre que analisarmos e encontrarmos dois for aninhados que iteram sobre o mesmo elemento pela mesma quantidade de vezes, podemos considerar um algoritmo quadrático.

#### Análise completa do algoritmo quadrático

Realizando a análise completa da função "superSumNumbers", vamos encontrar a seguinte expressão e o resultado da complexidade deo algoritmo.

```bash
O = 1 + (n * (n * (1 + 1))) + 1
O = 1 + (n * (n * 2)) + 1
O = 1 + (n * 2n) + 1
O = 1 + (2n²) + 1
O = 2 + 2n²
```

Agora vamos fazer algumas operações com a fórmula encontrada para entendermos melhor o crescimento das operações ao decorrer do crescimento do tamanho do input (n).

Se o tamanho do input for igual a 10, ou seja, n = 10, vamos ter a seguinte expressão:

```bash
O(2 + 2n²)
O(2 + 2*10²) = 2 + (2 * 10²)
O(2 + 2*10²) = 2 + (2 * 100)
O(2 + 2*10²) = 2 + 200
O(2 + 2*10²) = 202
```

Se o tamanho do input for igual a 1.000.000, ou seja, n = 1.000.000, vamos ter a seguinte expressão:

```bash
O(2 + 2n²)
O(2 + 2*1.000.000²) = 2 + (2 * 1.000.000²)
O(2 + 2*1.000.000²) = 2 + (2 * 1.000.000.000.000)
O(2 + 2*1.000.000²) = 2 + 2.000.000.000.000
O(2 + 2*1.000.000²) = 2.000.000.000.002
```

Podemos observar que algoritmos com notação Big O quadrático não são perfomáticos ou escaláveis, já que para um input com tamanho de 1 milhão, no pior dos casos, que é o que a análise assintótica visa encontrar, vamos ter dois trilhões e duas operações. Agora vamos simplificar a expressão, vamos encontrar o termo que faz o algoritmo escalar.

```bash
O(n²)
```

O maior termo do algoritmo analisado é o **n²**, já que é o termo que faz o algoritmo escalar. Dessa forma, vamos chamar essa função O de n ao quadrado O(n²)

#### Gráfico de um algoritmo quadrático O(n²)

![Gráfico de um algoritmo quadrático O(n²)](https://res.cloudinary.com/practicaldev/image/fetch/s--lVnY7ZAn--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://miro.medium.com/max/640/1%2AGKAnOWbIA7CRV4OUB3STZw.png)
<br>
[Eduardo Rabelo](https://dev.to/oieduardorabelo/os-fundamentos-da-notacao-big-o-1jbp)

### Notação Big O Constante ou O(1)

Algoritmos que, não importa o tamanho do input, sempre executarão no mesmo tempo. Vamos analisar uma função simples com complexidade O de 1 ou constante.

```go
func firstPosition(arr []int) int {
	return arr[0] // -> 1
}
```

A função acima pode receber uma array com 10 mil ou 10 bilhões de posições, o número de operações será o mesmo, já que só exite uma operação, retornar o primeiro elemento de um array, o que por sua vez tem complexidade contastante, já que muitas estruturas de dados nativas nas linguagens de programação buscam complexidade O de 1 ou próximo disso. A notação O de 1 seria a melhor opção, já que escala super bem, uma vez que não importa o tamanho do input, o número de operações sempre será o mesmo, sendo assim o caso ideal que buscamos nos algoritmos quando pensamos em performance e escalabilidade.

#### Gráfico de um algoritmo constante O(1)

![Gráfico de um algoritmo constante O(1)](https://res.cloudinary.com/practicaldev/image/fetch/s--ZGf9Fiwp--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://miro.medium.com/max/640/1%2AC--4xOJ1aDuUykTZ4z5UGg.png)
<br>
[Eduardo Rabelo](https://dev.to/oieduardorabelo/os-fundamentos-da-notacao-big-o-1jbp)

### Notação Big O Logarítimico ou O(log n)

Algoritmos O log n dividem o problema pela metade a cada passo, fazendo com que tenha um comportamento logarítimico.

Para entendermos melhor como funciona um algoritmo logarítimico, vamos observar a função de busca binária Binary Search que possui uma complexidade logarítimica.

```go
func BinarySearch(arr []int, target int) *int {
	head := 0
	last := len(arr) - 1

	for head <= last{
		middle := (head + last) / 2

		if arr[middle] == target {
			return &middle
		}

		if arr[middle] > target {
			last = middle - 1
		}else {
			head = middle + 1
		}
	}

	return nil
}
```

A característica de um algoritimo logarítimico é dividir o problema pela metade a cada operação, que é justamente o comportamento da função Binary Search. Analisando a função acima, podemos observar que a função recebe um array de inteiros ordenados e um valor para ser encontrado, a função primeiro busca o elemento do meio do array e verifica se é a valor que estamos buscando, caso não seja, fazemos a verificação se o valor encontrado é maior ou menor ao valor que estamos buscando.

Se o valor encontrado for menor, vamos agora dividir o array original pela metade, excluíndo todos os valores maiores que o valor que estamos buscando, dividindo assim o problema pela metade.

Novamente, fazemos buscamos o elemento do meio do array, se o elemento encontrado for maior do que estamos buscando, dividimos novamente o array original pela metade, dessa vez excluíndo todos os valores menores que o valor que estamos buscando, dividindo novamente o problema pela metade.

Continuamos nessa buscar até encontrarmos ou não valor, retornando assim o index do valor no array ou o tipo de dado nulo.

Esse é o comportamento clássico de um algoritmo de complexidade O log n do Big O que é a melhor complexidade depois do O de 1 que conseguimos encontrar.

#### Gráfico de um algoritmo logarítimico O(log n)

![Gráfico de um algoritmo Logarítimico O(log n)](https://res.cloudinary.com/practicaldev/image/fetch/s--wyNrN4oo--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://miro.medium.com/max/640/1%2AUHTWeGAoDrJL1mhvtKkVGw.png)
<br>
[Eduardo Rabelo](https://dev.to/oieduardorabelo/os-fundamentos-da-notacao-big-o-1jbp)

### Notação Big O Linear Logarítimico ou O(n log n)

Algoritmos lineares logarítimicos são geralmente associados com algoritmos de ordenação.

Devemos nos atentar que a complexidade Linear O(n) e Logarítimico O(log n) é diferente do Linear Logarítimico O(n log n), podemos notar observando o gráfico de diversas complexidades do Big O a seguir:

![Gráfico de um algoritmo Linear Logarítimico O(n log n)](https://miro.medium.com/v2/resize:fit:720/format:webp/1*hGmdZ3v2sGpY54K3eTNVkw.png)
<br>
[Toni Esteves](https://estevestoni.medium.com/iniciando-com-a-nota%C3%A7%C3%A3o-big-o-be996fa3b47b)

Dessa forma, é visível que o algoritmo Linear é mais escalável que o Linear Logarítimico e o Logarítimico é o mais escalável entre os dois.

### Notação Big O Exponencial ou O(2^n)

Algoritmos exponenciais normalmente envolvem passos recursivos onde o problema dobra a cada passo.

Esses tipos de complexidade geralmente não são muito usáveis, já que não escalam nada bem, um exemplo é o algoritmo de fibonacci.

```go
func fibonacci(num int) int{
	if num <= 1{
		return num
	}

	return fibonacci(num - 1) + fibonacci((num - 2))
}
```

A função de fibonacci utiliza a técnica de recursão e podemos expressar o número de operações em relação ao tamanho do input.

### Notação Big O Fatorial ou O(n!)

Algoritmos fatoriais são os piores casos de complexidade Big O. Normalmente envovem passos recursivos onde o problema cresce de forma fatorial a cada passo. Um bom exemplo e o Traveling Salesman Problem (TSP) ou caixeiro-viajante usando força bruta. Calculo de probabilidades e permutação também usam fatorial.

Um exemplo de um algoritmo de complexidade fatorial é o próprio cálculo matemático para encontrar o fatorial de um número, o qual podemos observar a seguir:

```go
func factorial(num int) int {
	if num <= 1 {
		return num
	}

	return factorial(num-1) * num
}
```

Agora vamos fazer algumas operações com o algoritmo fatorial para entendermos o qual ruim e a complexidade fatorial do Big O.

Se o tamanho do input for igual a 10, ou seja, n = 10, vamos ter a seguinte expressão:

```bash
O(n!)
O(10!) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1
O(10!) = 3.628.800
```

Podemos notar que para um input n de tamanho 10, o algoritmo irá realizar mais de 3 milhoões de operaçoes, o que podemos considerar nada escalável.

A seguir, temos um gráfico com todas as complexidade do Big O citadas até aqui.

![Gráfico de um algoritmo Fatorial O(n!)](https://www.freecodecamp.org/portuguese/news/content/images/2021/12/1_KfZYFUT2OKfjekJlCeYvuQ.jpeg)
<br>
[Big-O Cheat Sheet](https://www.bigocheatsheet.com/)

### Análise de Algoritmos

Quando fazemos a análise de um algoritmo, devemos fazer três análises, sendo elas do **melhor caso**, do **caso médio** e do **pior caso**.

#### Melhor Caso

A complexidade de um algoritmo quando os dados estão dispostos de forma que o desempenho do algoritmo é mais rápido e usa menos recursos computacionais.

#### Caso Médio

Refere-se ao desempenho médio do algoritmo considerando todas as possiveis entradas. Refere-se ao comportamento típico do algoritmo.

#### Pior Caso

Quando os dados estão dispostos de forma que o algoritmo utiliza o máximo de recursos computacionais. **Esse é o caso que você precisa realmente saber**.

### Analisando os três casos no algoritmo de Busca Linear

```go
func linearSearch(arr []int, target int) int {
	for i := 0; i < len(arr); i++ {
		if arr[i] == target {
			return i
		}
	}

	return -1
}
```

#### Complexidade de Tempo

- Melhor caso: Quando estamos buscando um elemento e o mesmo está na primeira posição, o algoritmo sempre realizará apenas uma operação, sendo assim, um algortimo com complexidade O(1).

- Caso médio: No caso médio, o valor a ser encontrado geralmente estará pelo meio da lista, um pouco mais ou menos, mas próximo ao meio, sendo assim um algoritmo O(n/2), mas no Big O Notation representamos apenas com o maior termo, logo a complexidade do algoritmo é O(n), mas lembrando que é O(n/2).

- Pior caso: O pior caso num algoritmo de busca linear e o valor a ser encontrado está na última posição ou não existir, já que o algoritmo terá que chega até o final da lista para encontrar ou não o valor, sendo assim uma complexidade de O(n).

#### Complexidade de Espaço

Complexidade de espaço nada mais é do que a quantidade de memória que um algoritmo aloca dependendo do tamanho do input durante sua execução e no caso do algoritmo de buscar linar visto acima, temos uma complexidade de espaço de O(1) nos três casos, já que não temos nenhuma aloação de memória não importa o tamanho do input.
