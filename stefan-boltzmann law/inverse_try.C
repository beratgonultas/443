{
  c1 = new TCanvas("c1","A graph with error bars");
   c1->SetGrid();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   const Int_t n = 12; //number of data points
   Double_t x[n]  ={2.4,
2.7,
3.1,
3.8,
4.1,
10.8,
20,
25.3,
29.3,
32,
35.9,
42.9
}; //x values
  
   Double_t y[n] = {0.026,
0.02,
0.016,
0.012,
0.01,
0.006,
0.002,
0.0003,
0.0002,
0.00015,
0.0001,
5E-05
}; //y values

   
   Double_t ex[n] ={0.173205080756888,
0.173205080756888,
0.173205080756888,
0.173205080756888,
0.173205080756888,
0.173205080756888,
0.173205080756888,
0.173205080756888,
0.173205080756888,
0.173205080756888,
0.173205080756888,
0.173205080756888
}; //error of x values
   
   Double_t ey[n] ={0.0002,
0.0002,
0.0002,
0.0002,
0.0002,
0.0002,
0.0002,
2E-04,
2E-04,
2E-04,
2E-04,
2E-04
}; //error of y values

   
   gr = new TGraphErrors(n,x,y,ex,ey);
   gr->SetTitle(";d(cm);V(Volts)");
   gr->SetMarkerColor(4);
   gr->SetMarkerStyle(21);
   gr->Draw("AP");
   
   TF1 *f = new TF1("f","x^(-[1])+[0]");
   f->SetLineColor(kRed+0);
   f->SetParameters(1, 1);
   gr->Fit("f");
   gStyle->SetOptStat(111110);
   gStyle->SetOptFit(1111);


   return c1;
}
