#!/bin/bash

# Uninstall library
arduino-cli lib uninstall me_ReadInteger

# Uninstall dependencies
arduino-cli lib uninstall \
  me_ParseInteger \
  me_SerialTokenizer \
  me_BaseTypes
