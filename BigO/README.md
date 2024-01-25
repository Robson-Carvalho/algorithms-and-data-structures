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
