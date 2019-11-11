{
  c1 = new TCanvas("c1","A graph with error bars");
   c1->SetGrid();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   const Int_t n = 10; //number of data points
   Double_t x[n]  ={-26.7,
-32.3,
-38.5,
-42.3,
-45.1,
-59.4,
-66,
-71.3,
-83.1,
-84.8,


}; //x values
  
   Double_t y[n] = {-6.3,
-13.9,
-22.1,
-27,
-31,
-49.4,
-57.8,
-64.8,
-79.6,
-81.6,



}; //y values

   
   Double_t ex[n] ={1.335,
1.615,
1.925,
2.115,
2.255,
2.97,
3.3,
3.565,
4.155,
4.24,


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
   gr->SetTitle(";Magnetic Field (mT);Voltage (mV)");
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
