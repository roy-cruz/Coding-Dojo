# PURSUE 2024 Coding Dojo

This is a group project. Take a buddy or make a group of 3. One person will be the driver, the rest observers.
The driver will code on the computer and the observers can give guidance.

## Gameplan

## Setup

First, fork this repository to your GitHub account. Next, open your terminal and connect to the LPC cluster (don't forget your port number!). Navigate to your `nobackup` directory and create a new directory where you will work. Create a CMSSW release by running the following commands:

```bash
source /cvmfs/cms.cern.ch/cmsset_default.sh
cmsrel CMSSW_14_1_0_pre3
```

Once it finished running, navigate into the `src` sub-directory. Start a virtual environment by running the following commands in sequence:

```src
cmsenv
scram-venv
cmsenv
```

Remember that if you disconnect from the LPC, when you re-connect you only have to run `cmsenv`.

Clone your branch of this repository and navigate into it. Next, download the data file we will be using with either `wget` or `curl`, and rename it to `data.root`. The data file can be obtained through the following link:

```
https://opendata.cern.ch/record/30525/files/assets/cms/Run2016G/JetHT/NANOAOD/UL2016_MiniAODv2_NanoAODv9-v1/130000/CD205112-3009-AB40-ACE1-9C3C31285B4A.root
```

Finally, start Jupyter Notebook and open the link provided in your browser.
