#ifndef TEST_TIME_SOURCE_INCLUDED
#define TEST_TIME_SOURCE_INCLUDED

class Test_TimeSource
{
  public:
    explicit Test_TimeSource();
    virtual ~Test_TimeSource();

  private:
    Test_TimeSource(const Test_TimeSource&);
    Test_TimeSource& operator=(const Test_TimeSource&);
};

#endif
