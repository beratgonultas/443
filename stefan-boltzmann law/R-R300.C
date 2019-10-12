{
  c1 = new TCanvas("c1","A graph with error bars");
   c1->SetGrid();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   const Int_t n = 18; //number of data points
   Double_t x[n]  ={1,
1.43,
1.87,
2.34,
2.85,
3.36,
3.88,
4.41,
4.95,
5.48,
6.03,
6.58,
7.14,
7.71,
8.28,
8.86,
9.44,
10.03,

}; //x values
  
   Double_t y[n] = {300,
400,
500,
600,
700,
800,
900,
1000,
1100,
1200,
1300,
1400,
1500,
1600,
1700,
1800,
1900,
2000,

}; //y values

   
   Double_t ex[n] ={0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,

}; //error of x values
   
   Double_t ey[n] ={0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,

}; //error of y values

   
   gr = new TGraphErrors(n,x,y,ex,ey);
   gr->SetTitle(";R/R300;Temperature(K)");
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
