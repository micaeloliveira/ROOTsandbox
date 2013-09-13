//Simple example of ROOT macro

void years2days(){
  
  vector <int> DATE;
  DATE.push_back(81002);
  DATE.push_back(90820);
  DATE.push_back(101031);
  
  double totalage=0;
  int years=0, months=0, days=0;
  for(int i=0; i<DATE.size(); i++){
    cout<<DATE[i]<<endl;
    
    double age = ConvertDate(DATE[i], years, months, days);
    
    cout<<"Years:   "<<years<<endl;
    cout<<"Months:  "<<months<<endl;
    cout<<"Days:    "<<days<<endl;
    
    cout<<age<<endl;
    
    totalage = totalage + age;
    
  }
  
  int y=0, m=0, d=0;
  int event = 121010;
  double eventdate = ConvertDate(event, y, m, d);
  
  cout<<eventdate/365. -  totalage/365./3.<<endl;
  
}//->End Main


double ConvertDate(int date, int &years, int &months, int &days){

  years  = (int) floor(date/10000.);
  months = (int) floor(date - years*10000.)/100.;
  days   = (int) floor(date - years*10000. - months*100.);
  
  double age = years*365.242 + months*30.437 + days;
  cout<<"Total age is: "<<age<<endl;
  return age;
  
}

/*--------------------------
CONVERSIONS

1 year  = 365,242 days
1 month = 30,437  days

--------------------------*/
