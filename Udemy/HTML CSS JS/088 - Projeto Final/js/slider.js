// dom elements
var sliderContainer = document.querySelector('.jl-slider-container');
var sliderList = document.querySelector('.jl-slider-list');
var sliderItems = document.querySelectorAll('.jl-portfolio-item');
var prevItem = document.querySelector('.jl-item-prev');
var nextItem = document.querySelector('.jl-item-next');
var currentSlide = document.querySelector('.jl-current-slide')
var totalSlide = document.querySelector('.jl-total-slides');
var navItems = document.querySelectorAll('.jl-item-navigator a');
var navCounter = document.querySelector('.jl-navigator-counter span');

totalSlide.innerHTML = sliderItems.length.toString().padStart(2, '0');

// variaveis de estado
var containerWidth = sliderContainer.parentElement.offsetWidth;
var sliderPos = 0;

// alterando larguras dinamicamente
sliderContainer.style.width = containerWidth + 'px';

sliderList.style.width = (containerWidth * sliderItems.length) + 'px';

for(var j = 0; j < sliderItems.length; j++)
{
    sliderItems[j].style.width = containerWidth + 'px';
}

document.querySelector('.jl-item-active').style.width = '90px';

// handlers

var slideAnim = function(){
    anime({
        targets: sliderList,
        translateX: -(containerWidth * sliderPos),
        easing: 'cubicBezier(0,1.01,.32,1)'
    });
}

var updateSliderCounter = function(newPos)
{
    currentSlide.innerHTML = newPos.toString().padStart(2, '0');
}

var updateNavCounter = function(newPos)
{
    navCounter.innerHTML = newPos.toString().padStart(2, '0');
}

var updateNavItems = function(newPos)
{
    for(item of navItems)
    {
        if(parseInt(item.getAttribute('data-nav')) === newPos)
        {
            item.classList.add('jl-item-active');
            anime({
                targets: item,
                width: 90
            })

            continue;
        }

        item.classList.remove('jl-item-active');
        anime({
            targets: item,
            width: 20
        })
    }
}

var updateSliderItems = function(newPos)
{
    for(item of sliderItems)
    {
        if(parseInt(item.getAttribute('data-slide')) === newPos)
        {
            item.classList.add('jl-slide-active');
            item.querySelector('.jl-portfolio-item-box').classList.add('jl-scale-right');
            item.querySelector('img').classList.add('jl-scale-up');
            item.querySelector('.jl-portfolio-item-info').classList.add('jl-fade-from-left');

            continue;
        }

        item.classList.remove('jl-slide-active');
        item.querySelector('.jl-portfolio-item-box').classList.remove('jl-scale-right');
        item.querySelector('img').classList.remove('jl-scale-up');
        item.querySelector('.jl-portfolio-item-info').classList.remove('jl-fade-from-left');
    }
}

// eventos

nextItem.addEventListener('click', function(){
    if(sliderPos >= sliderItems.length - 1)
    {
        return;
    }

    sliderPos += 1;

    updateNavCounter(sliderPos + 1);
    updateNavItems(sliderPos + 1);
    updateSliderItems(sliderPos + 1);
    updateSliderCounter(sliderPos + 1);
    slideAnim();
});

prevItem.addEventListener('click', function(){
    if(sliderPos <= 0)
    {
        return;
    }

    sliderPos -= 1;

    updateNavCounter(sliderPos + 1);
    updateNavItems(sliderPos + 1);
    updateSliderItems(sliderPos + 1);
    updateSliderCounter(sliderPos + 1);
    slideAnim();
});
