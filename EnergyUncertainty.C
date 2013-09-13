void EnergyUncertainty(){
  gRandom->SetSeed(99);

  TF1 *fgaus = new TF1("fgaus","gaus",-5,5);
  fgaus->SetParameter(0,0.75);
  fgaus->SetParameter(1,0);
  fgaus->SetParameter(2,0.3);

  TF1 *fgaus2 = new TF1("fgaus2","gaus",-5,5);
  fgaus2->SetParameter(0,0.5);
  fgaus2->SetParameter(1,0);
  fgaus2->SetParameter(2,0.8);

  fgaus->SetNpx(10000);
  fgaus2->SetNpx(10000);
  fgaus->SetLineColor(1); 
  fgaus2->SetLineColor(2);
  fgaus->SetLineWidth(3); 
  fgaus2->SetLineWidth(3);

  fgaus->SetTitle();
  fgaus->GetXaxis()->SetLabelSize(0);
  fgaus->GetYaxis()->SetLabelSize(0);
  fgaus->GetXaxis()->SetNdivisions(0);
  fgaus->GetYaxis()->SetNdivisions(0);

  TCanvas *c1 = new TCanvas("c1","",600,300);
  c1->cd();
  fgaus->Draw();
  fgaus2->Draw("SAME");

  c1->SaveAs("EnergyUncertainty.eps");


  TGraphAsymmErrors *gscat = new TGraphAsymmErrors();
  TGraph *gscat2 = new TGraph();
  Double_t x=0, xs=0, errx=0;
  Double_t y=0;
  Double_t a=0;
  int gp=0;
  for(int k=0; k<100; k++){

    x=gRandom->Uniform(100,150);
    xs = x + gRandom->Gaus(0,3);
    a=gRandom->Gaus(10,0.7);

    errx = xs-x;

    for(int ix=0; ix<5;ix++){
      y = a*x;

      gscat->SetPoint(gp, x, y);
      if(errx<0){
        gscat->SetPointError(gp, -errx+errx/10, 0, 0, 0);
      }
      else{
        gscat->SetPointError(gp, 0, errx-errx/10, 0, 0);
      }
      gscat2->SetPoint(gp, xs, y);

      gp++;
    }
  }
  TGraph *line = new TGraph();
  line->SetPoint(0, 120, 100);
  line->SetPoint(1, 120, 10000);
  line->SetLineColor(60);
  line->SetLineWidth(3);
  TGraph *line2 = new TGraph();
  line2->SetPoint(0, 130, 100);
  line2->SetPoint(1, 130, 10000);
  line2->SetLineColor(60);
  line2->SetLineWidth(3);

  gscat->GetXaxis()->SetLabelSize(0);
  gscat->GetXaxis()->SetNdivisions(205);
  gscat->GetYaxis()->SetNdivisions(205);
  gscat->GetYaxis()->SetLabelSize(0);

  TCanvas *c2 = new TCanvas("c2","",600,600);
  c2->cd();
  gscat->SetMarkerStyle(20);
  gscat2->SetMarkerStyle(20);
  gscat2->SetMarkerColor(2);
  gscat->Draw("AP|>");
  gscat2->Draw("SAMEP");
  line->Draw("SAMEL");
  line2->Draw("SAMEL");

  c2->SaveAs("EnergyScatter.eps");

}
