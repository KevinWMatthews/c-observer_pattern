#ifndef TEST_TIME_SOURCE_INCLUDED
#define TEST_TIME_SOURCE_INCLUDED

class Test_TimeObserver
{
  public:
    explicit Test_TimeObserver();
    virtual ~Test_TimeObserver();

  private:
    Test_TimeObserver(const Test_TimeObserver&);
    Test_TimeObserver& operator=(const Test_TimeObserver&);
};

#endif
