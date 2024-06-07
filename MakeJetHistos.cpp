/*
PURSUE 2024 Coding Dojo Bonus Exercise

This code makes a histogram of the Jet_pt branch of the data.root file and exports the histogram to a PNG file. Additionally, it has almost all of the neccesary components for making histograms of the other three branches
of interest. Modify this code so that it loops over all four branches and makes histograms of all of them.

To run:
- Make sure you have actiavted your CMSSW environment (`cmsenv`).
- Make your changes to this file and save it.
- Run this by doing: root -b -q 'MakeJetHistos.cpp("data.root")'

*/

void MakeJetHistos(const char* filename) {
    // RDataFrame from file
    ROOT::RDataFrame df("Events", filename);

    // Columns to be plotted
    std::vector<std::string> jetCols = {
        "Jet_pt",
        "Jet_eta",
        "Jet_phi",
        "Jet_mass"
    };

    // 2D array to hold the ranges for each histogram
    int histranges[4][2] = {
        {0, 100},
        {0, 100},
        {0, 100},
        {0, 100},
    };

    // TODO: Make a loop out of this which makes a plot of all of the branches specified in `jetCols`
    const auto& jetCol = jetCols[0];

    std::string histName = jetCol + "_Hist";
    std::string histTitle = jetCol + " Distribution;" + jetCol + ";Events";

    // Create histogram
    auto hist = df.Histo1D({histName.c_str(), histTitle.c_str(), 100, static_cast<double>(histranges[0][0]), static_cast<double>(histranges[0][1])}, jetCol);

    // Create canvas
    auto canvas = new TCanvas("canvas", (jetCol + " Histogram").c_str(), 800, 600);

    // Draw and save histogram
    hist->Draw();
    canvas->SaveAs((jetCol + "_histo.png").c_str());

    // Clean up
    delete canvas;
}