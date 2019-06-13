int pedirInt(int min, int max, int* valor, int intentos, char* mensaje, char* msjError);

int pedirFloat(float min, float max, float* valor, int intentos,  char* mensaje, char* msjError);

int pedirChar(char caracterA, char caracterB, char* letra, int intentos,  char* mensaje, char* msjError);

int pedirStringChar(int limite, char cadena[], int intentos,  char* mensaje, char* msjError);

int pedirStringNumero(int limite, char cadena[], int intentos,  char* mensaje, char* msjError);

int pedirTelefono(int limite, char cadena[], int intentos,  char* mensaje, char* msjError);

int pedirStringEmail(int limite, char cadena[], int intentos,  char* mensaje, char* msjError);

int soloLetras(char cadena[]);

int esNumerico(char str[]);

int esNumericoFlotante(char str[]);

int esEmail(char str[]);

int esTelefono(char str[]);
