<template>
    <div style="height:100%;width:100%;display: flex;flex-direction: column;">
        <n-layout-header style="height:100px;padding: 12px;" bordered>
            <MainHeader/>
        </n-layout-header>
        <n-layout
            style="padding-left: 20px;"
            :native-scrollbar="false"
            ref="content"
        >
            <Title/>
            <template v-for="item in lists" :key="item.id">
                <Content :user="item.user" :content="item.msg" class="animate__animated animate__bounceInRight"/>
            </template>
        </n-layout>
        <n-layout-footer style="background: transparent">
            <TextArea @input-msg="test"/>
        </n-layout-footer>
    </div>
</template>

<script>
import {defineComponent} from 'vue'
import Title from "@/components/view/Title";
import Content from "@/components/view/Content";
import TextArea from "@/components/view/TextArea";
import MainHeader from "@/components/layout/components/Main/Header";

export default defineComponent({
    name: "Main",
    data() {
        return {
            lists: [
                {id: 1, user: 'user1', msg: 'TESTTTTTTTTETSTSTE'},
                {id: 2, user: 'user2', msg: 'TESTTTTTTTTETSTSTE'},
                {id: 3, user: 'user3', msg: 'TESTTTTTTTTETSTSTE'},
            ],
            nextTodoId: 4
        }
    },
    components: {
        MainHeader,
        Content,
        Title,
        TextArea
    },
    methods: {
        test(data) {
            if (process.env.NODE_ENV == 'production')
                window.MsgHandler(data)
            this.lists.push({
                id: ++this.nextTodoId,
                user: window.user,
                msg: data
            })
            if (process.env.NODE_ENV == 'production') {
                this.$nextTick(() => {
                    this.$refs.content.scrollTo({
                        top: document.getElementsByClassName("n-scrollbar-content")[2].offsetHeight,
                        behavior: 'smooth'
                    })
                })
            } else {
                this.$nextTick(() => {
                    this.$refs.content.scrollTo({
                        top: document.getElementsByClassName("n-scrollbar-content")[2].__vnode.el.offsetHeight,
                        behavior: 'smooth'
                    })
                })
            }
        }
    }
})
</script>

<style scoped>

</style>
