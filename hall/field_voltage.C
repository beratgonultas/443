{
  c1 = new TCanvas("c1","A graph with error bars");
   c1->SetGrid();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   const Int_t n = 10; //number of data points
   Double_t x[n]  ={-32.3,
-37.8,
-46,
-53,
-57.8,
-62.6,
-65.4,
-74.7,
-82.4,
-85,



}; //x values
  
   Double_t y[n] = {14.8,
20.8,
31.6,
40.6,
46.8,
52.8,
56.6,
68.4,
78,
81.1,



}; //y values

   
   Double_t ex[n] ={1.615,
1.89,
2.3,
2.65,
2.89,
3.13,
3.27,
3.735,
4.12,
4.25,


}; //error of x values
   
   Double_t ey[n] ={0.1,
0.1,
0.1,
0.1,
0.1,
0.1,
0.1,
0.1,
0.1,
0.1,


}; //error of y values

   
   gr = new TGraphErrors(n,x,y,ex,ey);
   gr->SetTitle(";Magnetic Field(mT);Voltage(mV)");
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
