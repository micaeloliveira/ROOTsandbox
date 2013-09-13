//Uncertainty on the Energy
void EnergyBin(){

  gStyle->SetOptStat(0);
  
  int N=10000;
  
  TH1D *hR = new TH1D("hR","",55,18.45,19.55);
  formatH(hR);
  
  TH1D *hT = new TH1D("hT","",55,18.45,19.55);
  formatH(hT);
  
  for(int i=0;i<N;i++){
    hR->Fill(19.0);
    hT->Fill(gRandom->Gaus(19.0, 0.04));
  }


  TCanvas *cR = new TCanvas("cR","",600,600);
  cR->cd();
  hR->Draw();
  
  TCanvas *cT = new TCanvas("cT","",600,600);
  cT->cd();
  hT->Draw();
}

void formatH(TH1D *h){
  h->GetXaxis()->SetTitle("log_{10}(E/eV)");
  h->GetYaxis()->SetTitle("#");
  h->GetXaxis()->SetTitleOffset(1.3); 
  h->GetYaxis()->SetTitleOffset(1.3);
  h->SetLineWidth(4);
 }
