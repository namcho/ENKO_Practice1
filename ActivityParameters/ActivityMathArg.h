
typedef enum{

    ACTIVITY_MATH_OPER_SUM = 0,
    ACTIVITY_MATH_OPER_SUB,
    ACTIVITY_MATH_OPER_MUL,
    ACTIVITY_MATH_OPER_DIV,
}ActivityMathOperation_e;

typedef struct{

    ActivityMathOperation_e operation;

    float x1;           // Birinci sayiyi ifade eder
    float x2;           // ikinci sayiyi ifade eder
    float y;             // Yapilacak olan isleme gore sonucu barindirir

}ActivityMathArg_t;


void setActivityMathArg(ActivityMathArg_t *ActivityMathArgObj,
                        ActivityMathOperation_e operation,
                        float x1,
                        float x2
                        );

float getActivityMathResult(ActivityMathArg_t *ActivityMathArgObj);
