var snowFlag = 1;
var snowfont = {
    intervalRet: 0,
    start: function (elem) {
        this.elem = $(elem);
        snowfont.run();
    },
    
    stop: function() {
        if(!snowFlag) {
            window.clearInterval(this.intervalRet);
            $("#play").removeClass("disabled");
            $("#stop").addClass("disabled");
            snowFlag = 1;
        }
    },

    run: function(){
        if(snowFlag) {
            this.intervalRet = window.setInterval(function(){
                snowfont.entry();
            }, 300);
            $("#play").addClass("disabled");
            $("#stop").removeClass("disabled");
            snowFlag = 0;
        }
    },

    entry: function(str){
        var random = Math.floor(Math.random() * this.elem.length);
        var text = $(this.elem[random]).text(); 
        var left = ($(window).width() - $(".navbar").width())/2;
        var top = $(".navbar").position().top + $(".navbar").height();
        var stageHeight = $(window).height();
        var preRandomFontSize = Math.ceil(Math.random()*40);
        var randomEntry = Math.floor(Math.random()*($(".navbar").width()-$(this.elem[random]).width())) + left;
        var randomFontSize = preRandomFontSize + 10;
        var flakeName = 'flake-'+randomEntry;
        var grayScale = Math.ceil(Math.random()*256);
        var hue = 'rgb('+grayScale+','+grayScale+','+grayScale+ ')';
        $('<span />', { text: text, id: flakeName, })
        .addClass('snowfont')
        .css('left', randomEntry)
        .css('top', -10)
        .css('font-size', randomFontSize)
        .css('color', hue)
        .appendTo('body')
        .animate({
                "top": "+=" + stageHeight,
                opacity: 0
        }, 5000, function() {
                $('#'+flakeName).remove();                      
        }); 
    }
};

var oopts = {
    textFont: 'Impact,Arial Black,sans-serif',
    textHeight: 20,
    maxSpeed: 0.1,
    decel: 0.9,
    depth: 0.99,
    outlineColour: '#f6f',
    outlineThickness: 3,
    pulsateTo: 0.2,
    pulsateTime: 0.5,
    wheelZoom: false
}, ttags = 'taglist', lock, shape = 'sphere';

var tagclound = {
    init: function(tagcanvas, taglist) {
        TagCanvas.textColour = '#005580';
        TagCanvas.textHeight = 25;
        TagCanvas.outlineColour = '#333';
        TagCanvas.maxSpeed = 0.03;
        TagCanvas.minBrightness = 0.2;
        TagCanvas.depth = 0.92;
        TagCanvas.pulsateTo = 0.6;
        TagCanvas.initial = [0.1,-0.1];
        TagCanvas.decel = 0.98;
        TagCanvas.reverse = true;
        TagCanvas.hideTags = false;
        TagCanvas.shadow = '#ccf';
        TagCanvas.shadowBlur = 3;
        TagCanvas.weight = false;
        TagCanvas.imageScale = null;
        TagCanvas.Start(tagcanvas,taglist);
        TagCanvas.Start('smallCanvas','moreTags', oopts);
    },
};

!function($){
    prettyPrint();
    $().UItoTop({ easingType: 'easeOutQuart' });
    $(".excerpt").mouseenter(function(){
        $(this).stop().animate({boxShadow: '0 0 30px #444'});
    })
    $(".excerpt").mouseleave(function(){
        $(this).stop().animate({boxShadow: '0 0 10px #000'});
    })
}(window.jQuery);
