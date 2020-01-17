#include <DefaultEngine.h>
#include <charconv>
#include <string>
#pragma comment(lib,"WS2_32")



class YourEWrapper : public EWrapperL0 {
public:
  bool m_Done;
  bool m_ErrorForRequest;
  YourEWrapper(bool CalledFromThread = true) : EWrapperL0(CalledFromThread) {
    m_Done = false;
    m_ErrorForRequest = false;
  }

  virtual void winError(const IBString& str, int lastError) {
    fprintf(stderr, "WinError: %d = %s\n", lastError, (const char*)str);
    m_ErrorForRequest = true;
  }

  virtual void error(const int id, const int errorCode
    , const IBString     errorString) {
    fprintf(stderr, "Error for id=%d: %d = %s\n"
      , id, errorCode, (const char*)errorString);
    m_ErrorForRequest = (id > 0);
    // id == -1 are 'system' messages, not for user requests
  }

  virtual void historicalData(TickerId reqId, const IBString& date
    , double open, double high, double low, double close, int volume
    , int barCount, double WAP, int hasGaps) {

    if (IsEndOfHistoricalData(date)) {
      m_Done = true;
      return;
    }

    fprintf(stdout, "%10s, %5.3f, %5.3f, %5.3f, %5.3f, %7d\n"
      , (const  char*)date, open, high, low, close, volume);
  }

  virtual void updateMktDepth(TickerId id, int position, int operation, int side,
    double price, int size){
    
    /*
    printf("found id");
    cout << position << ' ' << operation << ' ' << price << endl;
    fprintf(stdout, "%10s, %5.3f, %5.3f, %5.3f, %7f\n"
      , position, operation, side, price, size);
      */


    // right now just logging otu all quotes
    DE_INFO(' ' + std::to_string(position)+
            ' ' + std::to_string(operation)+
            ' ' + std::to_string(side)+
            ' ' + std::to_string(price)+
            ' ' + std::to_string(size)
            );

    //        position, operation, side, price, size);



  }



};





class Sandbox : public DefaultEngine::Application
{
public:
	Sandbox()
	{

		test_func();

	}


	void test_func() {
		DE_INFO("Welcome to sandbox");

		//const char* result = test_twsapi();

		//DE_INFO(result);

    YourEWrapper mw(false);

    EClientL0* myclient = EClientL0::New(&mw);

		//EClientL0* myclient = get_client();

   
    Contract  C;
    //C.symbol = "ES";
    C.localSymbol = "ESH0";
    C.secType = *SecType::FUT;        //"STK"
    C.currency = "USD";
    C.exchange = *Exchange::GLOBEX;  //"SMART";
    //C.primaryExchange = *Exchange::CME;
    //C.expiry = "202003";
    //C.lastTradeDateOrContractMonth = "202003"
    

		if (myclient->eConnect("", 7497, 1)) {

			DE_INFO("connected on 7497");



      /*
      // call below gets old data
      myclient->reqHistoricalData(20
          , C
          , EndDateTime(2020, 01, 15)
          // Attention: for IB, this means last day will be 2013,02,19 
          , DurationStr(1, *DurationHorizon::Months)
          , *BarSizeSetting::_1_day
          , *WhatToShow::TRADES
          , UseRTH::OnlyRegularTradingData
          , FormatDate::AsDate
        );
      */


      // call below gets new data 

      myclient->reqMktDepth(20
        , C
        , 5
      );


        while (!mw.m_Done && !mw.m_ErrorForRequest)
          myclient->checkMessages();
      }

      DE_WARN("CLIENT DISCONNECTED");
      myclient->eDisconnect();
      delete myclient;

      return;


		}





	~Sandbox()
	{

	}

};

DefaultEngine::Application* DefaultEngine::CreateApplication()
{
	return new Sandbox();
}