/*
================================================================================
                            (Math Quiz Game)
================================================================================
وصف المشروع:
هذا البرنامج عبارة عن لعبة تفاعلية ممتعة تعمل على موجه الأوامر 
صُممت لاختبار وتطوير المهارات في العمليات الحسابية الأساسية.

مميزات اللعبة:
- مرونة التخصيص: يمكن للاعب تحديد عدد الأسئلة المطلوبة (من 1 إلى 10).
- مستويات متعددة: تتضمن مستويات صعوبة مختلفة (سهل، متوسط، صعب، ومختلط).
- عمليات متنوعة: تدعم الجمع، الطرح، الضرب، القسمة، أو اختيار تشكيلة عشوائية.
- تفاعل مباشر: تعطي تقييماً فورياً لكل إجابة مع تلوين الشاشة (أخضر للصواب، أحمر للخطأ).
- تقرير شامل: تعرض نتيجة نهائية توضح عدد الإجابات الصحيحة والخاطئة وحالة النجاح.

================================================================================
*/
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// تعريف مستويات الصعوبة
enum enQuizzLevel
{
    Easy = 1,
    Med = 2,
    Hard = 3,
    MixLevel = 4
};

// تعريف أنواع العمليات الحسابية
enum enOperationType
{
    Add = 1,
    Sub = 2,
    Mul = 3,
    Div = 4,
    MixOp = 5
};

// هيكل لتمثيل السؤال الواحد
struct stQuestions
{
    enOperationType OperationType;
    enQuizzLevel QuizzLevel;
    int Number1 = 0;
    int Number2 = 0;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};

// هيكل لتمثيل الاختبار بالكامل
struct stQuizz
{
    stQuestions QuestionsList[100];
    enQuizzLevel QustionsLevel;
    enOperationType OperationType;
    short NumberOfQuestions;
    short NumberOfRightAnswer = 0;
    short NumberOfWorngAnswer = 0;
    bool isPass = true;
};

// دالة لتوليد رقم عشوائي
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// دالة لقراءة عدد الأسئلة من المستخدم
short ReadQuestionNumber()
{
    short NumberOfQustions;
    do
    {
        cout << "How Many Questions Do You Want To Answer (1 To 10)? : ";
        cin >> NumberOfQustions;
    } while (NumberOfQustions < 1 || NumberOfQustions > 10);
    return NumberOfQustions;
}

// دالة لقراءة مستوى الصعوبة
enQuizzLevel ReadQuestionLevel()
{
    short QuestionLevel = 0;
    do
    {
        cout << "\nEnter Questions Level [1]: Easy, [2]: Med, [3]: Hard, [4]: Mix ? ";
        cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel > 4);
    return (enQuizzLevel)QuestionLevel;
}

// دالة لقراءة نوع العملية الحسابية
enOperationType ReadOperationType()
{
    short OperationType;
    do
    {
        cout << "\nEnter Operations Type [1]: Add, [2]: Sub, [3]: Mul, [4]: Div, [5]: Mix ? ";
        cin >> OperationType;
    } while (OperationType < 1 || OperationType > 5);
    return (enOperationType)OperationType;
}

// دالة للحصول على عملية حسابية عشوائية (في حالة اختيار Mix)
enOperationType GetRandomOperationType()
{
    int Op = RandomNumber(1, 4);
    return (enOperationType)Op;
}

// دالة لتقوم بالحساب الفعلي لإيجاد الإجابة الصحيحة
int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Sub:
        return Number1 - Number2;
    case enOperationType::Mul:
        return Number1 * Number2;
    case enOperationType::Div:
        if (Number2 == 0)
            Number2 = 1; // تجنب القسمة على صفر
        return Number1 / Number2;
    default:
        return Number1 + Number2;
    }
}

// دالة لتوليد سؤال واحد بناءً على المستوى ونوع العملية
stQuestions GenerateQuestion(enQuizzLevel QuizzLevel, enOperationType OpType)
{
    stQuestions Question;

    if (QuizzLevel == enQuizzLevel::MixLevel)
    {
        QuizzLevel = (enQuizzLevel)RandomNumber(1, 3);
    }
    if (OpType == enOperationType::MixOp)
    {
        OpType = GetRandomOperationType();
    }

    Question.OperationType = OpType;
    Question.QuizzLevel = QuizzLevel;

    switch (QuizzLevel)
    {
    case enQuizzLevel::Easy:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        break;
    case enQuizzLevel::Med:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        break;
    case enQuizzLevel::Hard:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        break;
    default:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
    }

    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
    return Question;
}

// دالة لتوليد جميع أسئلة الاختبار
void GeneratQuizzQuestions(stQuizz &Quizz)
{
    for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
    {
        Quizz.QuestionsList[Question] = GenerateQuestion(Quizz.QustionsLevel, Quizz.OperationType);
    }
}

// دالة للحصول على رمز العملية الحسابية كـ نص
string GetOperationTypeSymbol(enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return "+";
    case enOperationType::Sub:
        return "-";
    case enOperationType::Mul:
        return "x";
    case enOperationType::Div:
        return "/";
    default:
        return "Mix";
    }
}

// دالة لطباعة السؤال على الشاشة
void PrintTheQestions(stQuizz &Quizz, short QustionsNumber)
{
    cout << "\n";
    cout << "Question [" << QustionsNumber + 1 << "/" << Quizz.NumberOfQuestions << "] \n\n";
    cout << Quizz.QuestionsList[QustionsNumber].Number1 << endl;
    cout << Quizz.QuestionsList[QustionsNumber].Number2 << " ";
    cout << GetOperationTypeSymbol(Quizz.QuestionsList[QustionsNumber].OperationType);
    cout << "\n________________\n";
}

// دالة لقراءة إجابة اللاعب
int ReadQuestionAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}

// دالة لتغيير لون النص (مخصصة لبيئة لينكس)
void SetScreenColor(bool isRight)
{
    if (isRight)
    {
        cout << "\033[32m"; // لون أخضر للإجابة الصحيحة
    }
    else
    {
        cout << "\033[31m"; // لون أحمر للإجابة الخاطئة
        cout << "\a";       // صوت تنبيه للخطأ
    }
}

// دالة لتصحيح إجابة اللاعب وتسجيل النتيجة
void CorrectTheQuestionAnswer(stQuizz &Quizz, short QustionsNumber)
{
    if (Quizz.QuestionsList[QustionsNumber].PlayerAnswer != Quizz.QuestionsList[QustionsNumber].CorrectAnswer)
    {
        Quizz.QuestionsList[QustionsNumber].AnswerResult = false;
        Quizz.NumberOfWorngAnswer++;

        cout << "Wrong Answer :-( \n";
        cout << "The Right Answer Is: " << Quizz.QuestionsList[QustionsNumber].CorrectAnswer << "\n";
    }
    else
    {
        Quizz.QuestionsList[QustionsNumber].AnswerResult = true;
        Quizz.NumberOfRightAnswer++;

        cout << "Right Answer :-)\n";
    }
    cout << endl;
    SetScreenColor(Quizz.QuestionsList[QustionsNumber].AnswerResult);
}

// دالة لطرح الأسئلة وتصحيحها
void AskAndCorrectQuestionsListAnswer(stQuizz &Quizz)
{
    for (short QustionsNumber = 0; QustionsNumber < Quizz.NumberOfQuestions; QustionsNumber++)
    {
        PrintTheQestions(Quizz, QustionsNumber);
        Quizz.QuestionsList[QustionsNumber].PlayerAnswer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(Quizz, QustionsNumber);
    }
    Quizz.isPass = (Quizz.NumberOfRightAnswer >= Quizz.NumberOfWorngAnswer);
}

// دالة للحصول على نص النتيجة النهائية
string GetFinalResultText(bool Pass)
{
    if (Pass)
        return " P A S S ";
    else
        return " F A I L ";
}

// دالة للحصول على نص مستوى الصعوبة
string GetQustionsLevelText(enQuizzLevel QuestionLevel)
{
    string arrQuestonLevelText[4] = {"Easy", "Med", "Hard", "Mix"};
    return arrQuestonLevelText[QuestionLevel - 1];
}

// دالة لطباعة تفاصيل نتيجة الاختبار
void PrintQuizzReults(stQuizz Quizz)
{
    cout << "\t\tNumber of Questions     : " << Quizz.NumberOfQuestions << endl;
    cout << "\t\tQuestions Level         : " << GetQustionsLevelText(Quizz.QustionsLevel) << endl;
    cout << "\t\tOperation Type          : " << GetOperationTypeSymbol(Quizz.OperationType) << endl;
    cout << "\t\tNumber Of Right Answers : " << Quizz.NumberOfRightAnswer << endl;
    cout << "\t\tNumber Of Wrong Answers : " << Quizz.NumberOfWorngAnswer << endl;
    cout << "\t\t__________________________________________________________\n";
}

// دالة لعرض الشاشة النهائية للاختبار
void ShowFinalQuizzScreen(stQuizz Quizz)
{
    cout << "\n\t\t__________________________________________________________\n\n";
    cout << "\t\t\t\t+++ F I N A L  R E S U L T S +++\n";
    cout << "\t\t\t\t++++++++++++" << GetFinalResultText(Quizz.isPass) << "+++++++++++\n";
    cout << "\t\t__________________________________________________________\n\n";
    PrintQuizzReults(Quizz);
}

// دالة لتنظيف الشاشة وإعادة اللون الافتراضي (مخصصة لبيئة لينكس)
void ClearScreen()
{
    system("clear");
    cout << "\033[0m"; // إعادة لون النص إلى الافتراضي
}

// الدالة الرئيسية لتشغيل اللعبة
void PlayMathGame()
{
    stQuizz Quizz;

    Quizz.NumberOfQuestions = ReadQuestionNumber();
    Quizz.QustionsLevel = ReadQuestionLevel();
    Quizz.OperationType = ReadOperationType();

    GeneratQuizzQuestions(Quizz);
    AskAndCorrectQuestionsListAnswer(Quizz);
    ShowFinalQuizzScreen(Quizz);
}

// دالة بدء اللعبة
void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ClearScreen();
        PlayMathGame();

// إعادة لون النص إلى الافتراضي قبل سؤال اللاعب لتجنب بقاء اللون أحمر أو أخضر
        cout << "\033[0m";
        cout << "\nDo You Want To Play Again ? (Y/N): ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

// نقطة البداية
int main()
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}
