#errorCatcher Echo
#encoding UTF-8

## jQuery
<script type="text/javascript" src="js/jquery.min.js"></script>
## Bootstrap tooltips / JS
<script type="text/javascript" src="js/popper.min.js"></script>
<script type="text/javascript" src="js/bootstrap.min.js"></script>
## MDB core JavaScript
<script type="text/javascript" src="js/mdb.min.js"></script>
## Vendor JS
#if $Extras.language == "en"
<script src="js/vendor/moment.min.js"></script>
#else
<script src="js/vendor/moment-with-locales.min.js"></script>
<script type="text/javascript">moment.locale('$Extras.language')</script>
#end if
<script src="js/vendor/apexcharts/apexcharts.min.js"></script>
## NeoWX Material App
<script type="text/javascript" src="js/app.js"></script>

## Global apexcharts config
<script type="text/javascript">
    var theme_mode = 'light';
    if (window.matchMedia && window.matchMedia('(prefers-color-scheme: dark)').matches) {
        theme_mode = 'dark';
    }

    window.Apex = {
        theme: {
            mode: theme_mode,
            palette: '$Extras.Charts.palette'
        },
        dataLabels: {
            enabled: false
        },
        stroke: {
            curve: 'smooth',
            width: 2
        },
        markers: {
            size: 0,
        },
        chart: {
            height: 300,
            stacked: false,
            zoom: {
                type: 'x',
                enabled: true,
                autoScaleYaxis: true
            },
            toolbar: {
                autoSelected: 'zoom',
                export: {
                    csv: {
                        headerCategory: 'DateTime',
                        dateFormatter(timestamp) {
                            return moment.unix(timestamp).toISOString()
                        }
                    }
                }
            },
            locales: [
                #include raw "js/vendor/apexcharts/locales/" + $Extras.language + ".json"
            ],
            defaultLocale: '$Extras.language',
            animations: {
                enabled: false
            },
        },
    }
</script>