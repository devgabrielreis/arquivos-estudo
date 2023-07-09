let overlay = document.querySelector('.jl-overlay');
let frameContainer = document.querySelector('.jl-gallery-frame-container');
let frameImage = document.querySelector('.jl-gallery-frame-image');
let galleryImages = document.querySelectorAll('.jl-thumb-img');
let closeGallery = document.querySelectorAll('.jl-toggle-gallery');
let prevBtn = document.querySelector('.jl-item-prev');
let nextBtn = document.querySelector('.jl-item-next');
let galleryCounter = document.querySelector('.jl-current-slide');

document.querySelector('.jl-total-slides').innerHTML = galleryImages.length;

function toggleGalleryModal()
{
    overlay.classList.toggle('jl-is-open');
    frameContainer.classList.toggle('jl-is-open');
}

function updateGalleryModal(imgIndex)
{
    frameImage.setAttribute('src', galleryImages[imgIndex - 1].dataset.src);
    frameImage.setAttribute('data-index', galleryImages[imgIndex - 1].dataset.item);
    galleryCounter.innerHTML = imgIndex.toString().padStart(2, '0');
}

for(let img of galleryImages)
{
    img.addEventListener('click', function(){
        updateGalleryModal(parseInt(this.dataset.item));
        toggleGalleryModal();
    });
}

for(let item of closeGallery)
{
    item.addEventListener('click', toggleGalleryModal);
}

prevBtn.addEventListener('click', function(){
    let currentImgIndex = parseInt(frameImage.getAttribute('data-index'));
    
    if(currentImgIndex > 1)
    {
        updateGalleryModal(currentImgIndex - 1);
    }
});

nextBtn.addEventListener('click', function(){
    let currentImgIndex = parseInt(frameImage.getAttribute('data-index'));
    
    if(currentImgIndex < galleryImages.length)
    {
        updateGalleryModal(currentImgIndex + 1);
    }
});
