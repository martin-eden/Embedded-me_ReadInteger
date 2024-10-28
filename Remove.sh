#!/bin/bash

# Uninstall library
arduino-cli lib uninstall me_ReadInteger

# Uninstall dependencies
arduino-cli lib uninstall \
  me_ParseInteger \
  me_SerialTokenizer \
  me_MemorySegment \
  me_InstallStandardStreams \
  me_Uart \
  me_UartSpeeds \
  me_BaseTypes
