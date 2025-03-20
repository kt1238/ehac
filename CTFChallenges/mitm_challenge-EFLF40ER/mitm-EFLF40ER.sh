#!/bin/bash

WEBSERVICE_TO_HACK="https://ehacgw01.cs.york.ac.uk:2000/ctf-mitm"

# Secret key between you and the server S
KMS="1038124470796232051142314336935567989102563" # DO NOT EDIT
# ---------------------------------------------------------------------

function sanitise_b64() {
  echo ${1//+/%2b}
}
# ---------------------------------------------------------------------

function get_b64_output() {
  echo $1 | cut -d ':' -f 2 | awk '{print $1}'
}
# ---------------------------------------------------------------------

function injectS() {
  PAYLOAD=$(get_b64_output "$1")
  
  # ----------------------------------------------------------
  # Manipulation of the payload to send to S in the first step
  # ----------------------------------------------------------
  
  # We need to sanitise the "+" of base64 before sending it
  echo $(sanitise_b64 "$PAYLOAD")
}
# ---------------------------------------------------------------------

function injectA() {
  PAYLOAD=$(get_b64_output "$1")
  
  # -----------------------------------------------------------
  # Manipulation of the payload to send to A in the second step
  # -----------------------------------------------------------
  
  # We need to sanitise the "+" of base64 before sending it
  echo $(sanitise_b64 "$PAYLOAD")
}
# ---------------------------------------------------------------------

function mitm() {
  # Run the protocol
  step1=$(wget --no-check-certificate -q -O - "$WEBSERVICE_TO_HACK/A.php?step=1")
  echo "$step1"
  step2=$(wget --no-check-certificate -q -O - "$WEBSERVICE_TO_HACK/S.php?step=2&data=$(injectS "$step1")")
  echo "$step2"
  step3=$(wget --no-check-certificate -q -O - "$WEBSERVICE_TO_HACK/A.php?step=3&data=$(injectA "$step2")")
  echo "$step3"
  printf "\n$(wget --no-check-certificate -q -O - "$WEBSERVICE_TO_HACK/B.php?step=4&data=$(sanitise_b64 $(get_b64_output "$step3") )")\n"
}
# ---------------------------------------------------------------------

# Run the protocol
mitm

