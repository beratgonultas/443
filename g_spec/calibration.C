{
  c1 = new TCanvas("c1","A graph with error bars");
   c1->SetGrid();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   const Int_t n = 4; //number of data points
   Double_t x[n]  ={680.2,
1490,
1682,
867.4,



}; //x values
  
   Double_t y[n] = {511,
1172.45,
1333.51,
661.66,


}; //y values

   
   Double_t ex[n] ={0.8,
0.9,
0.9,
0.1,



}; //error of x values
   
   Double_t ey[n] ={

}; //error of y values

   
   gr = new TGraphErrors(n,x,y,ex,ey);
   gr->SetTitle(";Measured Peak(keV);Real Peak(keV)");
   gr->SetMarkerColor(4);
   gr->SetMarkerStyle(21);
   gr->Draw("AP");
   
   TF1 *f = new TF1("f","x*[1]+[0]");
   f->SetLineColor(kRed+0);
   f->SetParameters(1, 1);
   gr->Fit("f");
   gStyle->SetOptStat(111110);
   gStyle->SetOptFit(1111);


   return c1;
}
