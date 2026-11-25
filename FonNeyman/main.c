#include <stdio.h>

int main(void)
{
    //cpu_state[0] — счётчик команд (pc)
    //cpu_state[1] — аккумулятор (acc), хранит текущий результат
    //cpu_state[2] — регистр команд (ir), хранит текущий опкод
    //cpu_state[3] — вектор прерываний (адрес обработчика ошибок)
    //cpu_state[4] — флаг остановки (0 = работает, 1 = остановлен)
    //cpu_state[5] — код последней ошибки (0 = нет ошибки)
    //cpu_state[6] — резерв для будущих расширений
    //cpu_state[7] — резерв для будущих расширений
    int cpu_state[8] = {0};
    int memory[256] = {0};

    int n = 0;
    printf("ВВедите количество ячеек(до 256): ");
    if (scanf("%d",&n) != 1 || n <= 0 || n > 256){
        printf("Ошибка ввода количества ячеек\n");
        return 1;
    }

    printf("ВВедите %d чисел: ",n);
    for (int i = 0;i < n; i++)
    {
        if (scanf("%d", &memory[i]) != 1)
        {
            printf("Ошибка ввода числа\n");
            return 1;
        }
    }

    //memory[0] хранит вектор прерываний
    cpu_state[3] = memory[0];
    cpu_state[0] = 6; //первая команда начинается с 6 ячейки(1-5 данные)
    
    int int_count = 0;  // Защита от бесконечного зацикливания при повторном прерывании

    //Основной цикл работы процессора
    while (cpu_state[4]==0)
    {
        int pc = cpu_state[0];

        //Проверка выхода рс за рамки памяти 
        if (pc < 0 || pc >=256)
        {
            printf("pc=%d: ОШИБКА: выход за границы памяти\n", pc);
            cpu_state[5] = 1;
            cpu_state[0] = cpu_state[3];
            int_count++;
            if (int_count > 1){
                cpu_state[4] = 1 ;
            }
            continue;
        }
        //Выбор кода команды в регистр команд air
        cpu_state[2] = memory[pc];
        int cmd = cpu_state[2];

        //cmd 0: STOP
        if (cmd == 0)
        {
            printf("pc=%d: команда 0, acc=%d\n", pc, cpu_state[1]);
            cpu_state[4]=1;
            break;
        }

        //Проверка, операнд не выходит за границы
        if (pc + 1 >= 256)
        {
            printf("pc=%d: команда %d, ОШИБКА: выход за границы памяти\n",pc, cmd);
            cpu_state[5] = 1;
            cpu_state[0] = cpu_state[3];
            int_count++;
            if (int_count > 1)
            {
                cpu_state[4] = 1;
            }
            continue;
        }

        int operand = memory[pc + 1];

        //Проверка корректного адреса операнда
        if (operand < 0 || operand >= 256)
        {
            printf("pc=%d: команда: %d, operand=%d, ОШИБКА: выход за границы памяти\n",pc, cmd, operand);
            cpu_state[5] = 1;
            cpu_state[0] = cpu_state[3];
            int_count++;
            if (int_count > 1)
            {
                printf("pc=%d: команда=%d, operand=%d, ОШИБКА: выход за границы памяти(повторное прерывание)\n", pc, cmd, operand);
                cpu_state[4] = 1 ;
            }
            continue;
        }

        //"4"
        if (cmd == 1)
        {
            //1.Загрузить в аккумулятор значение из ячейки памяти
            cpu_state[1] = memory[operand];
            cpu_state[0] += 2;
            printf("pc=%d, команда 1, operand=%d, acc=%d\n",pc ,operand ,cpu_state[1]);
        } 
        else if (cmd == 2)
        {
            //2.Умножить аккумулятор на значение из ячейки памяти
            cpu_state[1] *= memory[operand];
            cpu_state[0] += 2;
            printf("pc=%d, команда 2, operand=%d, acc=%d\n",pc ,operand ,cpu_state[1]);
        }
        else if (cmd == 3)
        {
            //3.Разделить аккумулятор на значение из ячейки памяти
            if (memory[operand] == 0)
            {
                printf("pc=%d: команда 3, operand=%d, ОШИБКА: деление на 0\n", pc , operand);
                cpu_state[5] = 2;
                cpu_state[0] = cpu_state[3]; // переход по вектору прерываний
                int_count++;
                if(int_count > 1)
                {
                printf("pc=%d: команда 3, operand=%d, ОШИБКА: деление на 0(повторное прерывание)\n", pc , operand);
                cpu_state[4] = 1;
                }
            }
            else
            {
                cpu_state[1] /= memory[operand];
                cpu_state[0] += 2;
                printf("pc=%d: команда 3, operand=%d, acc=%d\n", pc ,operand ,cpu_state[1]);
            }
        }
        else if (cmd == 4)
        {
            //4.Безусловный переход(JUMP)
            cpu_state[0] = operand;
            printf("pc=%d: команда 4, operand=%d => pc=%d, acc=%d\n",pc ,operand ,cpu_state[0] ,cpu_state[1]);
        }
        else
        {
            printf("pc=%d: команда %d, ОШИБКА: неизвестная команда\n",pc ,cmd);
            cpu_state[5] = 3;
            cpu_state[0] = cpu_state[3];
            int_count++;
            if (int_count > 1 )
            {
                cpu_state[4] = 1;
            }
        }
    }

    if (cpu_state[5] != 0)
    {
        printf("Пограмма завершена с ошибкой\n");
    }
    else
    {
        printf("Программа завершена успешно\n");
    }

    return 0;
}