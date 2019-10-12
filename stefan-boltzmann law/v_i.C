{
  c1 = new TCanvas("c1","A graph with error bars");
   c1->SetGrid();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   const Int_t n = 15; //number of data points
   Double_t x[n]  ={2.76,
5.11,
11.98,
22.28,
25.97,
27.24,
31.43,
33.98,
37.1,
38.64,
40.4,
42.2,
51.8,
52.6,
66.5,

}; //x values
  
   Double_t y[n] = {0.7,
1.5,
3.5,
6.5,
7.6,
8,
9.3,
10,
10.9,
11.4,
11.9,
12.5,
15.3,
15.5,
19.7,

}; //y values

   
   Double_t ex[n] ={0.01,
0.01,
0.01,
0.01,
0.01,
0.01,
0.01,
0.01,
0.01,
0.01,
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
0.1,
0.1,
0.1,
0.1,
0.1,

}; //error of y values

   
   gr = new TGraphErrors(n,x,y,ex,ey);
   gr->SetTitle(";I(mA);V(mV)");
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
