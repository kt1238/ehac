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
  echo "[*] Running MITM attack..."

  # Step 1: Forge A's message using your token Z6NGZBDO
  step1="data: $(echo -n 'A,Z6NGZBDO' | base64)"
  echo -e "\nA -> S: $(echo -n 'A,Z6NGZBDO' | base64)"

  # Step 2: Send forged message to S
  step2=$(wget --no-check-certificate -q -O - "$WEBSERVICE_TO_HACK/S.php?step=2&data=$(injectS "$step1")")
  echo -e "\nS -> A: $(get_b64_output "$step2")"

  # Step 3: Send S's message to A
  step3=$(wget --no-check-certificate -q -O - "$WEBSERVICE_TO_HACK/A.php?step=3&data=$(injectA "$step2")")
  echo -e "\nA -> B: $(get_b64_output "$step3")"

  echo -e "\n[*] Use the A -> B base64 output above for manual splitting and decryption."
}
# ---------------------------------------------------------------------

# Run the protocol
mitm

