// 获取元素样式值
function getStyle(obj, name) {
    if (obj.currentStyle) { // 如果是IE浏览器（只有IE浏览器支持CURRENTSTYLE）
        return obj.currentStyle[name];
    } else { // 否则
        return getComputedStyle(obj, false)[name];
    }
}

// 将元素从当前值变成目标值，每一次按差值的1/6增长，形成渐变的感觉
function startMove(obj, arr, iTarget) {
    clearInterval(obj.timer);

    obj.timer = setInterval(function () {
        var cur = 0;
        if (arr == 'opacity') {
            cur = Math.round(parseFloat(getStyle(obj, arr)) * 100);
        } else {
            cur = parseInt(getStyle(obj, arr));
        }
        var speed = (iTarget - cur) / 6;
        speed = speed > 0 ? Math.ceil(speed) : Math.floor(speed);
        if (cur == iTarget) {
            clearInterval(obj.timer);
        } else {
            if (arr == 'opacity') {
                obj.style.filter = 'alpha(opcity:' + (cur + speed) + ')';
                obj.style.opacity = (cur + speed) / 100;

                //	document.getElementById('tex1').value = obj.style.opacity;
            } else {
                obj.style[arr] = cur + speed + 'px';
            }
        }
    }, 30);
}

function getByClass(oParent, sClass) {
    var aEle = oParent.getElementsByTagName('*');
    var aResult = [];

    for (var i = 0; i < aEle.length; i++) {
        if (aEle[i].className == sClass) {
            aResult.push(aEle[i]);
        }
    }
    return aResult;
}


window.onload = function () {
    var oDiv = document.getElementById('playimages');
    var oBtnPrev = getByClass(oDiv, 'prev')[0];
    var oBtnNext = getByClass(oDiv, 'next')[0];
    var oMarkLeft = getByClass(oDiv, 'mark_left')[0];
    var oMarkRight = getByClass(oDiv, 'mark_right')[0];

    var oDivSmall = getByClass(oDiv, 'small_pic')[0];
    var oUlSmall = oDivSmall.getElementsByTagName('ul')[0];
    var aLiSmall = oDivSmall.getElementsByTagName('li');


    var oUlBig = getByClass(oDiv, 'big_pic')[0];
    var aLiBig = oUlBig.getElementsByTagName('li');


    var nowZIndex = 2;
    var now = 0;
    oUlSmall.style.width = aLiSmall.length * aLiSmall[0].offsetWidth + 'px';

    // 左右按钮
    oBtnPrev.onmouseover = oMarkLeft.onmouseover = function () {
        startMove(oBtnPrev, 'opacity', 100);
    };
    oBtnPrev.onmouseout = oMarkLeft.onmouseout = function () {
        startMove(oBtnPrev, 'opacity', 0);
    };
    oBtnNext.onmouseover = oMarkRight.onmouseover = function () {
        startMove(oBtnNext, 'opacity', 100);
    };
    oBtnNext.onmouseout = oMarkRight.onmouseout = function () {
        startMove(oBtnNext, 'opacity', 0);
    };

    // 点击小图，切换大图
    for (var i = 0; i < aLiSmall.length; ++i) {
        aLiSmall[i].index = i;
        aLiSmall[i].onclick = function () {
            if (this.index == now) return;
            now = this.index;
            tab();
        }
        aLiSmall[i].onmouseover = function () {
            startMove(this, 'opacity', 100);
        };
        aLiSmall[i].onmouseout = function () {
            if (this.index != now) {
                startMove(this, 'opacity', 30);
            }
        };
    }

    // 切换大图
    function tab() {
        aLiBig[now].style.zIndex = nowZIndex++;

        for (var i = 0; i < aLiSmall.length; ++i) {
            startMove(aLiSmall[i], 'opacity', 30);
        }

        aLiBig[now].style.height = 0;
        startMove(aLiBig[now], 'height', 480);
        startMove(aLiSmall[now], 'opacity', 100);
        if (now == 0) {
            startMove(oUlSmall, 'left', 0);
        } else if (now == aLiSmall.length - 1) {
            startMove(oUlSmall, 'left', -(now - 2) * aLiSmall[0].offsetWidth);
        } else {
            // 负号：向左偏移多少多少
            startMove(oUlSmall, 'left', -(now - 1) * aLiSmall[0].offsetWidth);
        }
    }
    oBtnPrev.onclick = function () {
        --now;
        if (now == -1) {
            now = aLiSmall.length - 1;
        }
        tab();
    }
    oBtnNext.onclick = function () {
        ++now;
        if (now == aLiSmall.length) {
            now = 0;
        }
        tab();
    };
    var timer = setInterval(oBtnNext.onclick, 2000);
    oDiv.onmouseover = function () {
        clearInterval(timer);
    };
    oDiv.onmouseout = function () {
        timer = setInterval(oBtnNext.onclick, 2000);
    };
};