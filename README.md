# WeerliveClass

This is a small test suite to test the working of
this WeerliveClass

In `WeerliveClass.cpp` in the function `configureFilters()` you can add or remove
fields.
```
/**
* Configures the filters for weather data.
*/

void Weerlive::configureFilters() 
{
    filter["liveweer"][0]["plaats"]   = true;
    filter["liveweer"][0]["time"]     = true;
    filter["liveweer"][0]["temp"]     = true;   //-- actuele temperatuur in graden Celsius
    filter["liveweer"][0]["gtemp"]    = false;  //-- gevoeld temperatuur
    filter["liveweer"][0]["samenv"]   = true;   //-- samenvatting
    filter["liveweer"][0]["lv"]       = true;   //-- relatieve luchtvochtigheid
    filter["liveweer"][0]["windr"]    = true;   //-- windrichting
    filter["liveweer"][0]["windrgr"]  = false;  //-- windrichting in graden
    filter["liveweer"][0]["windms"]   = false;  //-- windkracht in m/s
    filter["liveweer"][0]["windbft"]  = false;  //-- windkracht in bft
    filter["liveweer"][0]["winds"]    = true;   //-- windsnelheid in m/s
    filter["liveweer"][0]["windknp"]  = true;   //-- windsnelheid in knoppen
    filter["liveweer"][0]["windkmh"]  = false;  //-- windsnelheid in km/h
    filter["liveweer"][0]["luchtd"]   = true;   //-- luchtdruk
    filter["liveweer"][0]["ldmmhg"]   = false;  //-- luchtdruk in mmHg
    filter["liveweer"][0]["dauwp"]    = true;   //-- dauwpunt
    filter["liveweer"][0]["zicht"]    = true;   //-- zicht in meters
    filter["liveweer"][0]["gr"]       = true;   //-- globale (zonne)straling in Watt/M2
    filter["liveweer"][0]["verw"]     = true;   //-- korte dagverwachting
    filter["liveweer"][0]["sup"]      = false;  //-- zon op
    filter["liveweer"][0]["sunder"]   = true;   //-- zon onder
    filter["liveweer"][0]["image"]    = true;   //-- afbeeldingsnaam
    filter["liveweer"][0]["alarm"]    = true;   //-- Geldt er een weerwaarschuwing? 1 = ja, 0 = nee
    filter["liveweer"][0]["lkop"]     = true;   //-- Weerwaarschuwing korte omschrijving
    filter["liveweer"][0]["ltekst"]   = true;   //-- Langere beschrijving van de waarschuwing
    filter["liveweer"][0]["wrschklr"] = false;  //-- KNMI kleurcode voor jouw regio
    filter["liveweer"][0]["wrsch_g"]  = true;   //-- Moment waarop de eerstkomende KNMI-waarschuwing geldt
    filter["liveweer"][0]["wrsch_gts"]= false;  //-- Timestamp van wrsch_g
    filter["liveweer"][0]["wrsch_gc"] = true;   //-- KNMI kleurcode voor de eerstkomende waarschuwing

} //  configureFilters()
```

In `myCredentials_org.h` you must modify:
```
const char * ssid     = "YOUR_WIFI_SSID";
const char * password = "YOUR_WIFI_PASSWORD";
```
And you have to provide the Weerlive AUTH key and city of interest!
```
const char *AUTHKEY   = "12345678";
const char YOURCITY   = "Amsterdam";
```
## DON'T FORGET
Rename `myCredentials_org.h` to `myCredentials.h`
