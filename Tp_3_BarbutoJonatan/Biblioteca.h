// Validaciones //


int Validate_OnlyNumberInt(char* buffer);
int Validate_OnlyNumberFloat(char* buffer);
int Validate_OnlyAlphabet(char* buffer);
int Validate_OnlyAphabetWithSpaces(char* buffer);
int Validate_Exit_SN(char* MSJ, char* ERROR_MSJ, int REINTENTOS);
int Validate_Cuit(char* pData);

// Get //

int Get_Int(char* MSJ, char* ERROR_MSJ);
int Get_IntRange(char* MSJ, char* ERROR_MSJ, int MIN, int MAX, int REINTENTOS);
int Get_IntPositive(char* MSJ, char* ERROR_MSJ, int REINTENTOS);
int Get_IntNegative(char* MSJ, char* ERROR_MSJ, int REINTENTOS);
float Get_Float(char* MSJ, char* ERROR_MSJ, int REINTENTOS);
float Get_FloatRange(char* MSJ, char* ERROR_MSJ, float MIN, float MAX, int REINTENTOS);
char Get_Char(char* MSJ, char* ERROR_MSJ, int REINTENTOS);
void Get_String(char* MSJ, char* ERROR_MSJ, char* pString, int size, int REINTENTOS);
void Get_OnlyAlphabetString(char* MSJ, char* ERROR_MSJ, char* pString, int size, int REINTENTOS);
void Get_OnlyAlphabetStringWithSpaces(char* MSJ, char* ERROR_MSJ, char* pString, int size, int REINTENTOS);
void Get_Cuil(char* MSJ, char* ERROR_MSJ, char* pString, int size, int REINTENTOS);
void Get_DNI(char* MSJ, char* ERROR_MSJ, char* pString, int size, int REINTENTOS);
