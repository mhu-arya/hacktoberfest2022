#include <stdio.h>
int main()
{
    float celsius, fahrenheit, kelvin, rankine, reaumur;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;
    kelvin = (celsius + 273.15);
    rankine = (celsius + 273.15) * 1.8;
    reaumur = (celsius * 0.8);
    
    printf("%.2f Celsius = %.2f Fahrenheit", celsius, fahrenheit);
    printf("\n");
    printf("%.2f Celsius = %.2f Kelvin", celsius, kelvin);
    printf("\n");
    printf("%.2f Celsius = %.2f Rankine", celsius, rankine);
    printf("\n");
    printf("%.2f Celsius = %.2f Reaumur", celsius, reaumur);
    
    return 0;
}
