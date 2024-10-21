#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.3(it).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestSortByRowDuplicates)
        {
            int rowCount = 3;
            int colCount = 4;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                a[i] = new int[colCount];
            }

            // Заповнення тестовими даними
            a[0][0] = 1; a[0][1] = 2; a[0][2] = 3; a[0][3] = 4;  
            a[1][0] = 1; a[1][1] = 1; a[1][2] = 2; a[1][3] = 2;  
            a[2][0] = 3; a[2][1] = 3; a[2][2] = 3; a[2][3] = 1;  

            // Сортування
            SortByRowDuplicates(a, rowCount, colCount);

            // Перевірка результатів
            Assert::AreEqual(a[0][0], 1);
            Assert::AreEqual(a[0][1], 2);
            Assert::AreEqual(a[0][2], 3);
            Assert::AreEqual(a[0][3], 4);  

            Assert::AreEqual(a[1][0], 1);
            Assert::AreEqual(a[1][1], 1);
            Assert::AreEqual(a[1][2], 2);
            Assert::AreEqual(a[1][3], 2);  

            Assert::AreEqual(a[2][0], 3);
            Assert::AreEqual(a[2][1], 3);
            Assert::AreEqual(a[2][2], 3);
            Assert::AreEqual(a[2][3], 1); 

            for (int i = 0; i < rowCount; i++) {
                delete[] a[i];
            }
            delete[] a;
        }
    };
}