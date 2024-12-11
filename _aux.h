#define X 1031

struct placa {
  char placa[8];
};
typedef struct placa Placa;

extern Placa vetor[X];

unsigned int hash(char placa[], int tentativa);

int inserirPlaca(char placa[]);

int buscar(char placa[], Placa vetor[]);

void remover(char placa[], Placa vetor[]);

void gerarRelatorio(double tempo, int tam);

void gerarRelatorioInsercao(int totalColisoes, double tempo, int tam);