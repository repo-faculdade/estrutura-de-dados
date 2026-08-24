using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

/*
 * =====================================================================
 *  TRABALHO: Análise do algoritmo QuickSort
 * =====================================================================
 *
 *  ESTRATÉGIA DO ALGORITMO (para a parte de explicação da avaliação):
 *
 *  O QuickSort é um algoritmo de ordenação "dividir para conquistar"
 *  (divide and conquer). A ideia central é:
 *
 *    1. Escolher um elemento do vetor chamado PIVÔ.
 *    2. PARTICIONAR o vetor: todos os elementos menores que o pivô
 *       ficam à esquerda dele, e todos os maiores ficam à direita.
 *       Ao final da partição, o pivô já está na sua posição final.
 *    3. Aplicar recursivamente o mesmo processo para a sub-lista da
 *       esquerda e para a sub-lista da direita.
 *    4. A recursão termina quando a sub-lista tem 0 ou 1 elemento
 *       (já está ordenada por definição).
 *
 *  Complexidade:
 *    - Caso médio / melhor caso: O(n log n)
 *    - Pior caso (ex: vetor já ordenado, dependendo da escolha do
 *      pivô): O(n²)
 *
 *  Isso é justamente o motivo do experimento: comparar o desempenho
 *  do QuickSort em 3 cenários diferentes (ordenado, parcialmente
 *  ordenado e totalmente desordenado), pois a organização inicial
 *  dos dados afeta diretamente o tempo de execução.
 * =====================================================================
 */

class Program
{
    // Contador global só para a demonstração visual (não afeta o QuickSort "real")
    static int passoAtual = 0;

    static void Main(string[] args)
    {
        Console.OutputEncoding = Encoding.UTF8;

        // ---------------------------------------------------------------
        // 1) Pequena demonstração visual do QuickSort passo a passo,
        //    usando um vetor pequeno e aleatório (ótimo para print/slide
        //    da apresentação).
        // ---------------------------------------------------------------
        DemonstracaoVisual();

        // ---------------------------------------------------------------
        // ) Experimento principal: lê os 3 arquivos, ordena cada um
        //    e mede o tempo de execução.
        // ---------------------------------------------------------------
        string[] arquivos =
        {
            "src/ordenado.txt",
            "src/parcialmenteOrdenado.txt",
            "src/totalmenteDesordenado.txt"
        };

        // Guarda os resultados para montar a tabela final
        var resultados = new (string situacao, int quantidade, double tempoMs)[arquivos.Length];

        for (int i = 0; i < arquivos.Length; i++)
        {
            string caminho = arquivos[i];

            if (!File.Exists(caminho))
            {
                Console.WriteLine($"[AVISO] Arquivo não encontrado: {caminho}");
                continue;
            }

            int[] numeros = LerArquivo(caminho);

            // Stopwatch é a forma padrão do .NET de medir tempo de execução
            Stopwatch cronometro = Stopwatch.StartNew();

            QuickSort(numeros, 0, numeros.Length - 1);

            cronometro.Stop();

            string situacao = NomeSituacao(caminho);
            resultados[i] = (situacao, numeros.Length, cronometro.Elapsed.TotalMilliseconds);

            // Salva o resultado ordenado (opcional, útil para conferência)
            File.WriteAllLines("ordenado_" + Path.GetFileName(caminho), numeros.Select(n => n.ToString()));
        }

        // ---------------------------------------------------------------
        // 4) Apresentação dos resultados em forma de tabela
        // ---------------------------------------------------------------
        ImprimirTabelaResultados(resultados);

        Console.WriteLine("\nPressione qualquer tecla para sair...");
        Console.ReadKey();
    }

    // =====================================================================
    //  QUICKSORT
    // =====================================================================

    /// <summary>
    /// Ordena o vetor 'arr' entre os índices [low, high] usando QuickSort.
    /// </summary>
    static void QuickSort(int[] arr, int low, int high)
    {
        if (low < high)
        {
            // particiona o vetor e obtém a posição final do pivô
            int posicaoPivo = Particionar(arr, low, high);

            // ordena recursivamente a parte da esquerda e a da direita
            QuickSort(arr, low, posicaoPivo - 1);
            QuickSort(arr, posicaoPivo + 1, high);
        }
    }

    /// <summary>
    /// Particiona o vetor usando o último elemento como pivô (esquema de Lomuto).
    /// Ao final, o pivô estará na posição correta e retorna esse índice.
    /// </summary>
    static int Particionar(int[] arr, int low, int high)
    {
        int pivo = arr[high];
        int i = low - 1; // índice do último elemento menor que o pivô

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivo)
            {
                i++;
                Trocar(arr, i, j);
            }
        }

        Trocar(arr, i + 1, high);
        return i + 1;
    }

    static void Trocar(int[] arr, int a, int b)
    {
        (arr[a], arr[b]) = (arr[b], arr[a]);
    }
    static void DemonstracaoVisual()
    {
        Console.WriteLine("=====================================================");
        Console.WriteLine(" DEMONSTRAÇÃO VISUAL DO QUICKSORT (vetor pequeno)");
        Console.WriteLine("=====================================================");

        int[] exemplo = { 8, 3, 7, 1, 9, 2, 5 };
        Console.WriteLine("Vetor inicial: " + string.Join(", ", exemplo));
        Console.WriteLine();

        passoAtual = 0;
        QuickSortVisual(exemplo, 0, exemplo.Length - 1);

        Console.WriteLine();
        Console.WriteLine("Vetor final ordenado: " + string.Join(", ", exemplo));
        Console.WriteLine("=====================================================\n");
    }

    /// <summary>
    /// Mesma lógica do QuickSort, mas imprimindo o estado do vetor a cada
    /// partição, para poder mostrar visualmente o processo na apresentação.
    /// </summary>
    static void QuickSortVisual(int[] arr, int low, int high)
    {
        if (low < high)
        {
            int pivo = arr[high];
            int i = low - 1;

            for (int j = low; j < high; j++)
            {
                if (arr[j] < pivo)
                {
                    i++;
                    (arr[i], arr[j]) = (arr[j], arr[i]);
                }
            }
            (arr[i + 1], arr[high]) = (arr[high], arr[i + 1]);
            int posicaoPivo = i + 1;

            passoAtual++;
            Console.WriteLine($"Passo {passoAtual}: pivô = {pivo} | vetor agora: [{string.Join(", ", arr)}] " +
                               $"| pivô fixado na posição {posicaoPivo}");

            QuickSortVisual(arr, low, posicaoPivo - 1);
            QuickSortVisual(arr, posicaoPivo + 1, high);
        }
    }
    static int[] LerArquivo(string caminho)
    {
        return File.ReadAllLines(caminho)
                    .Where(linha => !string.IsNullOrWhiteSpace(linha))
                    .Select(linha => int.Parse(linha.Trim()))
                    .ToArray();
    }

    static string NomeSituacao(string caminhoArquivo)
    {
        string nome = Path.GetFileNameWithoutExtension(caminhoArquivo);
        return nome switch
        {
            "ordenado" => "Ordenado",
            "parcialmenteOrdenado" => "Parcialmente ordenado",
            "totalmenteDesordenado" => "Totalmente desordenado",
            _ => nome
        };
    }

    // =====================================================================
    //  TABELA DE RESULTADOS
    // =====================================================================

    static void ImprimirTabelaResultados((string situacao, int quantidade, double tempoMs)[] resultados)
    {
        Console.WriteLine("=====================================================");
        Console.WriteLine(" RESULTADOS DO EXPERIMENTO");
        Console.WriteLine("=====================================================");
        Console.WriteLine($"{"Situação inicial",-25} {"Qtd. elementos",-16} {"Tempo (ms)",-12}");
        Console.WriteLine(new string('-', 55));

        foreach (var r in resultados)
        {
            if (r.situacao == null) continue;
            Console.WriteLine($"{r.situacao,-25} {r.quantidade,-16} {r.tempoMs,-12:F4}");
        }

        Console.WriteLine("=====================================================");
    }
}
