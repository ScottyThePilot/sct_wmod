(([] call sct_wmod_fnc_getFrameworkDataCached) select 0) apply {
  [_x call sct_wmod_fnc_createInteraction, [], _this select 0]
}
