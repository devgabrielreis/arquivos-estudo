<?php
    include_once("templates/header.php");

    if(isset($_GET["id"]))
    {
        $postId = $_GET['id'];
        $currentPost;

        foreach($posts as $post)
        {
            if($post['id'] == $postId)
            {
                $currentPost = $post;
                
            }
        }
    }
?>

<main id="post-container">
    <div class="content-container">
        <h1 class="main-title"><?php echo $currentPost["title"] ?></h1>
        <p id="post-description"><?php echo $currentPost["description"] ?></p>
        <div class="img-container">
            <img src="<?php echo $BASE_URL ?>/img/<?php echo $currentPost["img"] ?>" alt="<?php echo $currentPost["title"] ?>">
        </div>
        <p class="post-content">Lorem ipsum dolor sit amet consectetur adipisicing elit. Voluptatem ipsum ut, alias cum quam rerum. Sequi, dicta tempore rerum blanditiis illo, distinctio debitis tenetur cumque quod, iusto illum ipsa quibusdam. Lorem ipsum dolor sit, amet consectetur adipisicing elit. Vitae sed voluptatibus hic necessitatibus reiciendis ullam at, neque fugit eius pariatur, culpa eveniet veritatis dolorum aliquid nesciunt, sit dolore distinctio minus? Lorem ipsum, dolor sit amet consectetur adipisicing elit. Laboriosam unde magni natus amet praesentium ducimus eaque incidunt iusto quasi possimus, facilis molestias. Doloribus error non placeat iure optio dolore aliquam. Lorem ipsum dolor sit amet, consectetur adipisicing elit. Eligendi nihil molestias culpa eos minima accusantium dicta reiciendis sapiente quas exercitationem? Aut commodi illo fugit, molestiae veritatis minus distinctio quam ipsam. Lorem ipsum dolor sit amet consectetur adipisicing elit. Accusamus dolorem aperiam nihil nulla praesentium ipsam expedita dolorum similique. Laudantium, quod! Fuga earum obcaecati illum ducimus rem a temporibus eligendi suscipit.</p>
        <p class="post-content">Lorem ipsum dolor sit amet consectetur adipisicing elit. Voluptatem ipsum ut, alias cum quam rerum. Sequi, dicta tempore rerum blanditiis illo, distinctio debitis tenetur cumque quod, iusto illum ipsa quibusdam. Lorem ipsum dolor sit, amet consectetur adipisicing elit. Vitae sed voluptatibus hic necessitatibus reiciendis ullam at, neque fugit eius pariatur, culpa eveniet veritatis dolorum aliquid nesciunt, sit dolore distinctio minus? Lorem ipsum, dolor sit amet consectetur adipisicing elit. Laboriosam unde magni natus amet praesentium ducimus eaque incidunt iusto quasi possimus, facilis molestias. Doloribus error non placeat iure optio dolore aliquam. Lorem ipsum dolor sit amet, consectetur adipisicing elit. Eligendi nihil molestias culpa eos minima accusantium dicta reiciendis sapiente quas exercitationem? Aut commodi illo fugit, molestiae veritatis minus distinctio quam ipsam. Lorem ipsum dolor sit amet consectetur adipisicing elit. Accusamus dolorem aperiam nihil nulla praesentium ipsam expedita dolorum similique. Laudantium, quod! Fuga earum obcaecati illum ducimus rem a temporibus eligendi suscipit.</p>
    </div>

    <aside id="nav-container">
        <h3 id="tags-title">Tags</h3>
        <ul id="tag-list">
            <?php foreach($currentPost["tags"] as $tag) : ?>
                <li><a href="#"><?php echo $tag ?></a></li>
            <?php endforeach; ?>
        </ul>

        <h3 id="categories-title">Categorias</h3>
        <ul id="categories-list">
            <?php foreach($categories as $category) : ?>
                <li><a href="#"><?php echo $category ?></a></li>
            <?php endforeach; ?>
        </ul>
    </aside>
</main>

<?php
    include_once("templates/footer.php");
?>
