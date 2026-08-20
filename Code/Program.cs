using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Collections.Generic;
class Program
{
    // Altere para false quando não quiser exibir os passos
    const bool mostrarPassos = false;

    static void Main()
    {
        string pastaSrc = Path.Combine(Directory.GetCurrentDirectory(), "src");

        string[] arquivos =
        {
            "ordenado.txt",
            "parcialmenteOrdenado.txt",
            "totalmenteDesordenado.txt"
        };

        string[] situacoes =
        {
            "Ordenado",
            "Parcialmente ordenado",
            "Totalmente Desordenado"
        };

        Console.WriteLine("Resultados da ordenação QuickSort");
        Console.WriteLine();

        Console.WriteLine("{0,-20} {1,-25} {2}",
            "Situação inicial",
            "Quantidade de elementos",
            "Tempo de ordenação");

        Console.WriteLine(new string('-', 75));

        var resultados = new List<string>();

        for (int i = 0; i < arquivos.Length; i++)
        {
            string caminho = Path.Combine(pastaSrc, arquivos[i]);

            if (!File.Exists(caminho))
            {
                Console.WriteLine($"Arquivo não encontrado: {caminho}");
                continue;
            }

            int[] valores = File.ReadAllText(caminho)
                .Split(new[] { ' ', '\n', '\r', '\t', ',', ';' },
                    StringSplitOptions.RemoveEmptyEntries)
                .Select(int.Parse)
                .ToArray();

            // A medição não inclui as mensagens exibidas na tela
            Stopwatch cronometro = Stopwatch.StartNew();

            QuickSort(valores, 0, valores.Length - 1, false, 0);

            cronometro.Stop();

            resultados.Add(
                $"{situacoes[i],-20} {valores.Length,-25} " +
                $"{cronometro.Elapsed.TotalMilliseconds:F6} ms"
            );

            if (mostrarPassos)
            {
                Console.WriteLine();
                Console.WriteLine($"========== PASSOS: {situacoes[i]} ==========");

                int[] copia = (int[])valores.Clone();

                // Para visualizar a ordenação desde o início,
                // é necessário ler novamente o arquivo original.
                copia = File.ReadAllText(caminho)
                    .Split(new[] { ' ', '\n', '\r', '\t', ',', ';' },
                        StringSplitOptions.RemoveEmptyEntries)
                    .Select(int.Parse)
                    .ToArray();

                QuickSort(copia, 0, copia.Length - 1, true, 0);

                Console.WriteLine("Vetor ordenado:");
                ImprimirVetor(copia);
                Console.WriteLine();
            }
            Console.WriteLine("Pressione uma tecla para continuar...");
            Console.ReadKey();
        }

        Console.WriteLine();
        Console.WriteLine("Resultados:");
        Console.WriteLine(string.Join("\n", resultados));
    }

    static void QuickSort(
        int[] vetor,
        int inicio,
        int fim,
        bool exibirPassos,
        int nivel)
    {
        if (inicio >= fim)
            return;

        string espacos = new string(' ', nivel * 2);

        if (exibirPassos)
        {
            Console.WriteLine(
                $"{espacos}QuickSort({inicio}, {fim})");
        }

        int posicaoPivo = Particionar(
            vetor,
            inicio,
            fim,
            exibirPassos,
            nivel);

        QuickSort(
            vetor,
            inicio,
            posicaoPivo - 1,
            exibirPassos,
            nivel + 1);

        QuickSort(
            vetor,
            posicaoPivo + 1,
            fim,
            exibirPassos,
            nivel + 1);
    }

    static int Particionar(
        int[] vetor,
        int inicio,
        int fim,
        bool exibirPassos,
        int nivel)
    {
        string espacos = new string(' ', nivel * 2);

        int pivo = vetor[fim];
        int indiceMenor = inicio - 1;

        if (exibirPassos)
        {
            Console.WriteLine(
                $"{espacos}Pivô escolhido: {pivo}");
        }

        for (int i = inicio; i < fim; i++)
        {
            if (exibirPassos)
            {
                Console.WriteLine(
                    $"{espacos}Comparando {vetor[i]} com o pivô {pivo}");
            }

            if (vetor[i] <= pivo)
            {
                indiceMenor++;

                if (indiceMenor != i)
                {
                    if (exibirPassos)
                    {
                        Console.WriteLine(
                            $"{espacos}Troca: {vetor[indiceMenor]} " +
                            $"<-> {vetor[i]}");
                    }

                    Trocar(vetor, indiceMenor, i);
                }
            }
        }

        Trocar(vetor, indiceMenor + 1, fim);

        if (exibirPassos)
        {
            Console.WriteLine(
                $"{espacos}Pivô {pivo} colocado na posição " +
                $"{indiceMenor + 1}");

            Console.Write($"{espacos}Vetor atual: ");
            ImprimirVetor(vetor);
        }

        return indiceMenor + 1;
    }

    static void Trocar(int[] vetor, int primeiro, int segundo)
    {
        int temporario = vetor[primeiro];
        vetor[primeiro] = vetor[segundo];
        vetor[segundo] = temporario;
    }

    static void ImprimirVetor(int[] vetor)
    {
        Console.WriteLine("Índice | Valor");
        Console.WriteLine("-------|------");

        for (int i = 0; i < vetor.Length; i++)
        {
            Console.WriteLine($"{i,6} | {vetor[i],5}");
        }
    }
}