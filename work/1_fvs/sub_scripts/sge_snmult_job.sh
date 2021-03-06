#!/bin/bash
#$ -S /bin/bash
#$ -cwd


## Sophie King  soph.e.king123@gmail.com
## Expanded version of submission scripts written by Mark Hartz

## Written for SGE batch system
## source /opt/sge/default/common/settings.sh
## qsub job.sh

## ---- Systematic submission scripts ---- ##
## For a given systematic 'X'
## sge_X_loop.sh submits multiple instances of sge_X_job.sh
## sge_X_job.sh sources sge_job_options.sh and runs sge_job_framework.sh with the corresponding variables set for syst X
## sge_job_framework.sh executes 'flux_throws' for syst X
## User instructions:  Set variables in sge_job_options.sh, set SGE setup file in sge_X_loop.sh and run sge_X_loop.sh
## --------------------------------------- ##


## This file:  sge_na61_job.sh
## Sets na61 inputs for flux_throws 


 # --------------------- #
 # For systematic:  na61 #

  echo Perform an extra throw and subtract 1 for SNMULT
  echo The job with throw set to -1 calculates the nomimal flux for the purpose of the system covariance calculation

  throw=${1}
  $((throw--))
  export THROW=${throw}
  
  echo THROW = ${THROW}

  export FOLDER="snmult_outputs"
  export NAME="SNMULT"
  export ARG="-type SNMULT  -throw ${THROW}"
 # --------------------- #

 
 ./sge_job_framework.sh
