{
  c1 = new TCanvas("c1","A graph with error bars");
   c1->SetGrid();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   const Int_t n = 10; //number of data points
   Double_t x[n]  ={0.0156,
0.03078,
0.03922,
0.0519,
0.0605,
0.0718,
0.0924,
0.1166,
0.1306,
0.1758,


}; //x values
  
   Double_t y[n] = {0.719,
1.398,
1.786,
2.417,
2.825,
3.367,
4.35,
5.57,
6.36,
8.88,


}; //y values

   
   Double_t ex[n] ={1E-05,
1E-05,
1E-05,
0.0001,
0.0001,
0.0001,
0.0001,
0.0001,
0.0001,
0.0001,


}; //error of x values
   
   Double_t ey[n] ={0.001,
0.001,
0.001,
0.001,
0.001,
0.001,
0.01,
0.01,
0.01,
0.01,

}; //error of y values

   
   gr = new TGraphErrors(n,x,y,ex,ey);
   gr->SetTitle(";Current(A);Voltage(V)");
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
