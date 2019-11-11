{
  c1 = new TCanvas("c1","A graph with error bars");
   c1->SetGrid();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   const Int_t n = 10; //number of data points
   Double_t x[n]  ={10.45,
34.68,
51,
69.1,
92.6,
108.8,
131.3,
148.3,
169.9,
182.6,




}; //x values
  
   Double_t y[n] = {5.8,
19.4,
28.6,
39,
53.1,
63.7,
80,
92.5,
109.2,
121.8,




}; //y values

   
   Double_t ex[n] ={0.01,
0.01,
0.1,
0.1,
0.1,
0.1,
0.1,
0.1,
0.1,
0.1,


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
   gr->SetTitle(";Current(mA);Voltage(mV)");
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
